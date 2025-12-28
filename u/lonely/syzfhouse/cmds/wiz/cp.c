// cp.c
// created by Doing

#include <ansi.h>

inherit F_CLEAN_UP;

int copy_dir(string src, string dst, int dir_existed);
int help(object me);
void assure_file(string file);

// value of call parameter
#define DIR_EXISTED         1
#define DIR_MAY_NOT_EXISTED     0

int main(object me, string arg)
{
    string *fn;
    string src, dst;
    int copy_dir;
    int count;

	seteuid(geteuid(me));

    if (! arg)
    {
        help(me);
        return 1;
    }

    if (sscanf(arg, "-R %s %s", src, dst) == 2)
    {
        if (me && ! is_root(me))
        {
            write("只有管理員才能使用 -R 參數。\n");
            return 1;
        }

        copy_dir = 1;
    }
    else
    if (sscanf(arg, "%s %s", src, dst) == 2)
    {
        copy_dir = 0;
    }
    else
    {
        write("格式錯誤！\n");
        help(me);
        return 1;
    }

    src = resolve_path(me->query("cwd"), src);
    dst = resolve_path(me->query("cwd"), dst);

    switch (file_size(src))
    {
        case -1:
        write("沒有這個(" + src + ")文件或目錄，無法複製。\n");
        return 1;

        case -2:
        if (copy_dir) break;
        write("沒有指定 -R 參數，不能複製目錄(" + src + ")。\n");
        return 1;

        default:
        // copy file, not directory.
        copy_dir = 0;
        break;
    }

    if (! copy_dir)
    {
        if (file_size(dst) == -2)
        {
            // destination is a directory
            fn = explode(src, "/");
            dst += "/" + fn[sizeof(fn) - 1];
            fn = 0;
        }

        SECURITY_D->backup_file(dst);
        if (cp(src, dst) == 1)
            write("Ok.\n");
        else
        {
            if (! SECURITY_D->valid_read(src, me, "ls"))
                write("沒有這個(" + src + ")文件或目錄，無法複製。\n");
            else
    		    write("你沒有權限複製這個文件。\n");
        }
        return 1;
    }

    if (strlen(dst) >= strlen(src) && dst[0..strlen(src) - 1] == src)
    {
        write("你不能將一個路徑複製到自身或者是子路徑中。\n");
        return 1;
    }

    switch (file_size(dst))
    {
    case -2:
        // destination is a directory
        fn = explode(src, "/");
        dst += "/" + fn[sizeof(fn) - 1];
        fn = 0;
        break;
    case -1:
        // no destination
        break;

    default:
        // destition is a file, error
        write("目錄不能複製到文件內，請修正你的目的路徑。\n");
        return 1;
    }

	message("system",HIC "\n複製目錄中，請稍候...\n" NOR,users());

    count = copy_dir(src, dst, DIR_MAY_NOT_EXISTED);
    if (count)
        write(HIY "總共有" + count + "個文件被成功複製。\n" NOR);
    return 1;
}

int copy_dir(string src, string dst, int dir_existed)
{
    mixed *file;
    int count;
    int i;

    if (! is_root(previous_object()))
        return 0;

    count = 0;
    if (src[strlen(src) - 1] != '/') src += "/";
    if (dst[strlen(dst) - 1] != '/') dst += "/";

    // assure dst existed
    if (! dir_existed) assure_file(dst);

    file = get_dir(src, -1);
	if (! sizeof(file))
        return count;

    if(wizardp(previous_object()))
    {
        write (HIC "複製目錄(" + src + ") -- > (" + dst + ")。\n" NOR);
	}
	i = sizeof(file);
	while (i--)
    {
		reset_eval_cost();
		if (file[i][1] != -2)
            if (cp(src + file[i][0], dst + file[i][0]))
                count++;
	}

	i = sizeof(file);
	while (i--)
    {
		reset_eval_cost();
		if (file[i][1] == -2)
        {
            mkdir(dst + file[i][0]);
            count += copy_dir(src + file[i][0],
                      dst + file[i][0],
                      DIR_EXISTED);
        }
    }
	return count;
}

void assure_file(string file)
{
    string path, *dir;
    int i;

    if (file_size(file) != -1) return;

    seteuid(ROOT_UID);
    dir = explode(file, "/");

    if (file[strlen(file) - 1] != '/')
        // the file is refer to a file, not directory
        dir = dir[0..sizeof(dir)-2];

    path = "/";
    for (i = 0; i < sizeof(dir); i++)
    {
        path += dir[i];
        mkdir(path);
        path += "/";
    }

    dir = 0;
}
int help(object me)
{
    write(@HELP

指令格式 : cp [-R] <文件|路徑名> <目的文件|目的路徑名>

這個指令可以複製源文件成目的文件或複製到目的路徑。如果使用了參數-R則
可以複製一個目錄，沒有這個參數則不能複製路徑。

see also: rm, mv

HELP);
    return 1;
}
