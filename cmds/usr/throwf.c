// redl 2014
#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me);

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        object obj;
        string no_tell, can_tell;

        if (me->is_busy()) 
                return notify_fail("你現在正忙著呢。\n");
 
                me->start_busy(5); 
 
        if( wiz_level(me) < 1 )
                return notify_fail("你沒有這個權力。\n");

        if (! arg || arg == "")
                return notify_fail("你是打算禁閉誰？\n");

        if( arg == query("id", me) )
                return notify_fail("你有病？\n");

        obj = find_player(arg);

        if (! obj || ! me->visible(obj)) 
                return notify_fail("沒有這個人。\n");

          if ( wiz_level(obj) >= wiz_level(me) )
                return notify_fail("你權限不足。\n");


                tell_object(me, "注意：\n只能懲罰chat頻道刷屏的人，禁止濫用，\n對於聊天室裡非chat的刷屏者，先使用push來制止。\n如果確定要繼續使用輸入y:\n"); 
                input_to("get_input", me, obj);

        return 1;
}

int do_beep(object obj)
{
        if (! obj) return 1;
        tell_object(obj, "\a", 0);
        return 1;
}

protected void get_input(string arg, object me, object obj)
{
        if (!arg || arg!="y") {
                tell_object(me, "你寬容地打消了念頭。\n"); 
                return;
        }
        call_out("do_beep", 1, obj); 
        call_out("do_beep", 2, obj); 
        call_out("do_beep", 3, obj); 
        call_out("do_beep", 4, obj); 
    set("active",0,obj);
        get_object("/u/redl/prison")->throw_flood(me, obj); 
}


int help(object me)
{
        write(@HELP
指令格式：throwf <某人>

因為某人刷屏而禁閉他一段時間，懲罰時間遞增，有記錄。（導師權限以上可用）

HELP);
        return 1;
}


