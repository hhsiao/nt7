// typeset.c
// Write by Lonely
// Rewrite by zjpwxh@sjpl
// 修正了顯示效果，增加自動判定特殊房間
#include <ansi.h>
inherit F_CLEAN_UP;
int to_format(object me, string dir, int n);
int do_format(string file, int n);
int help(object me);
void create() { seteuid(getuid()); }
int main(object me, string arg) {
    string dir;
    int n;

    if (! SECURITY_D->valid_grant(me, "(wizard)"))
        return 0;


    if (! arg || sscanf(arg, "%s %d", dir, n) != 2)
        return help(me);
    if (n < 1)
        return help(me);

    if (file_size(dir) == -1)
        dir = resolve_path(me->query("cwd"), dir);
    if (dir[strlen(dir) - 1] != '/')
        dir += "/";

    if (file_size(dir) != -2)
        return notify_fail(dir + " 並不是一個目錄。\n");

    if (dir[0..2] != "/d/" && dir[0..2] != "/u/")
        return notify_fail("為確保安全，只允許更改/d/和/u/目錄下面的房間描述。\n");
    write(HIW "系統批量檔案處理中，請耐心等候...\n" NOR);
    to_format(me, dir, n);

    write(HIW "\n系統批量檔案處理完畢！\n" NOR );

    return 1;
}
int to_format(object me, string dir, int n) {
    int i, j, l, eff, num;
    mixed *file;
    string filename;

    file = get_dir(dir, -1);
    if (! sizeof(file))
    {
        if (file_size(dir) == -2)
        {
            write("\n"HIC + dir + "這個目錄是空的。\n"NOR);
            log_file("empty_dir", dir + "\n");
        }
        return 1;
    }

    write(HIC "\n現在系統正在批處理 " + HIW + dir + NOR + HIC " 目錄房間描述...\n" + HIG "進度：" + process_bar(100) + "\n");

    num = 0;
    eff = 0;
    i = sizeof(file);

    for(j = 0; j<i; j++ )
    {
        if (file[j][1] != -2)
            eff++;
    }

    while (i--)
    {
        reset_eval_cost();
        if (file[i][1] != -2)
        {
            num++;
            filename = file[i][0];
            l = strlen(filename);
            if (filename[l - 1] != 'c' || filename[l - 2] != '.')
                continue;
            if (!do_format(dir + filename, n) )
                return 0;
            write(ESC + "[1A"+ESC + "[200D" + HIG "進度：" + process_bar((num + 1) * 100 / eff ) + "\n" );
        }
    }
    write(HIG"目錄： " + HIW + dir + HIC" 下共有 " + HIR + num + NOR + HIC" 個房間描述整理成功！\n" NOR);

    i = sizeof(file);
    while (i--)
    {
        reset_eval_cost();
        if (file[i][1] == -2 && file[i][0] != "npc" && file[i][0] != "obj" )
        {
            file[i][0] += "/";
            if (!to_format(me, dir + file[i][0], n) )
                return 0;
        }
    }

    return 1;
}
int do_format(string file, int n) {
    int i, begin1, begin2;
    string *filetext, *temptext;
    object ob;
    string long, err;
    string str1, str2, tempstr;

    err = catch(call_other(file, "???"));
    if (err)
    {
        log_file("typeset", sprintf("%s ERROR ** \n%s\n", file, err));
        return 0;
    }
    if (! (ob = get_object(file)))
    {
        log_file("typeset", sprintf("%s can not be load.\n", file));
        return 0;
    }

    if(!ob->query("long") || ob->query("spec_long") )
    {
        log_file("spec_long", sprintf("%s\n\n", file) + sprintf("%s\n\n\n", ob->query("long")) );

        if (clonep(ob) && ! userp(ob))
            destruct(ob);

        return 2;
    }

    long = replace_string(ob->query("long"), "\n", "");
    long = replace_string(long, " ", "");
    long = replace_string(long, "“", "『");
    long = replace_string(long, "”", "』");
    long = replace_string(long, "<", "『");
    long = replace_string(long, ">", "』");
    long = replace_string(long, ",", "，");
    long = replace_string(long, ".", "。");
    long = replace_string(long, "?", "？");
    long = replace_string(long, ";", "；");
    long = replace_string(long, ":", "：");
    long = replace_string(long, "!", "！");

    filetext = explode(read_file(file), "\n");
    n *= 2;
    temptext = explode(sort_string(long, n, 4) + "\n", "\n");
    temptext -= ({ "" });
    begin1 = 0;
    begin2 = 0;
    for (i = 0;i < sizeof(filetext);i ++)
    {
        tempstr = "";
        tempstr = replace_string(filetext[i], " ", "");
        tempstr = replace_string(tempstr, "\t", "");
        if (strsrch(tempstr, "set(\"long\",") != -1)
        {
            begin1 = i;
        }
        if (strsrch(tempstr, "\);") != -1 && begin1)
        {
            begin2 = i;
            break;
        }
    }
    if (! begin1 || ! begin2)
    {
        log_file("typeset", sprintf("ROOM %s 的描述沒有被成功定位！\n", file));
        return 0;
    }
    str1 = "     set\(\"long\", @LONG\n";
    str2 = "LONG \);\n";
    rm(file);
    for (i = 0; i < begin1; i ++)
        write_file(file, filetext[i] + "\n", 0);
    write_file(file, str1, 0);

    for (i = 0; i < sizeof(temptext); i ++)
        write_file(file, temptext[i] + "\n", 0);
    write_file(file, str2, 0);
    for (i = begin2 + 1; i < sizeof(filetext); i ++)
        write_file(file, filetext[i] + "\n", 0);
    return 1;
}
int help(object me) {
    write(@HELP
指令格式 : typeset <目錄名> <字數>
這個指令可以將某個目錄下所有的房間的長描述自動排版成每行
為指定數目的漢字，當然第一行是少二個漢字的。
HELP );
    return 1;
}
