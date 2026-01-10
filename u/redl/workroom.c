// This program is a part of NITAN MudLIB
// redl 2012/11/1
#include <ansi.h>
#include <room.h>
inherit CREATE_CHAT_ROOM;

int clean_up(int inherited) { return 1;}
string look_ting(object me);
int is_chat_room() { return 1; }
int climbing(object me);
int stop_climbing(object me);

void create()
{
                set("short", "東籬翠微");
                set("long",
"這是一處山坡小院的重陽節傍晚。五棵柳樹圍在翠綠的籬笆外抽枝\n"
"舞絮，籬內貼著若干株李花桃花隨風飄飛。\n"
"    幾條小徑把院落分出幾個出口，中心圍攏處是一小"+CYN+"亭"+NOR+"，亭內有一石\n"
"桌和幾張石凳。繞亭遍栽層疊起伏的金菊白菊當此節氣正怒放爭嬈，卻\n"
"合柳絮桃花自成一派詭譎風光。\n"
                );
        set("item_desc", ([
                "亭": (: look_ting :),
                "ting": (: look_ting :),
        ]) );
        set("objects", ([
//               __DIR__"obj/putiye" : 3,
        ]));
                set("exits", ([ /* sizeof() == */
                        "east" : __DIR__"modaotang1",
                  "enter" : __DIR__"modaotang3",
                      "southeast" : __DIR__"tianshenzoulang",
                        "west" : __DIR__"swing",
                        "down" : "/d/city/guangchang",
                "shen" : "/d/emei/xixiangchi",
                "gan" : "/d/item/xiaowu",
                      "bfd4" : "/d/emei/xue/bfde4",
                      "bfd5" : "/d/emei/xue/bfde5",
 "lgt" : "/d/kaifeng/linggt/lgtd",
"houzi" : "/d/huashan/houzhiwangyu",
"was" : "/d/tulong/yitian/was_lou4",
"xb" : "/d/item/xuanbing1",
      "chuan" : "/u/redl/teleport/yuanjiang/chuancenter",

                ]));

                set("valid_startroom", 1);
                set("no_fight", "1");
                set("no_clean_up", 0);
                set("no_rideto", 1);
                set("no_flyto", 1);
                setup();
//      call_other("/clone/board/redl_b","???");
}

int valid_leave(object me, string dir)
{
                //if (dir == "wiz" && ! wizardp(me) && (query("id", me) != "redl"))
                //return notify_fail("那裡只有巫師才能進去。\n");

                return ::valid_leave(me, dir);
}

int do_clnew2(string arg, object me)
{
        object ob;
        int i = 50;

        while (i--) {
                ob = new(arg);
                if (!ob || !objectp(ob)) {
                        write("no target.\n");
                        return 1;
                }
                ob->move(me, 1);
        }
        me->command("store all");
    write("ok.\n");
                delete("clonenew");
    return 1;
}

int do_clnew(string arg)
{
        object me = this_player();

        if (!arg) return notify_fail(NOR "你需要輸入物件。\n"NOR );
        if (query("clonenew")) {
                return 1;
        }
        set("clonenew", 1);
                call_out("do_clnew2", 1, arg, me);
        return 1;
}

void init()
{
                string obid = query("id", this_player());
                object me;

                if (playerp(this_player())) {
                        me = find_player("redl");
                        if (objectp(me) && obid!=query("id", me))
                                tell_object(me, HIG + "工作室有"+ obid + "造訪！\a\n" + NOR);
                        me = find_player("red");
                        if (objectp(me) && obid!=query("id", me))
                                tell_object(me, HIG + "工作室有"+ obid + "造訪！\a\n" + NOR);
                }

                                add_action("do_clnew", "clnew");
                add_all_action();
                /*if (living(this_player()) && !wizardp(this_player()))
                {
                this_player()->start_busy(bind((:call_other, __FILE__, "climbing" :), this_player()),
                           bind((:call_other, __FILE__, "stop_climbing" :), this_player()));
                this_player()->set_short_desc("正在攀登山坡。");
        }*/
}

string look_ting(object me)
{
    return "                  "+HIR+BCYN+"『煉心亭』\n"+HIW+BCYN+
    "\n「無可奈何花落去」"+NOR+"          "+HIW+BCYN+"「似曾相識燕歸來」\n\n\n"+NOR+
        "              小亭入口上方橫掛匾額，兩排楹聯豎刻於亭柱木匾上，\n"+
        "                           落款為紅蓮老祖(redl)於二零一二年冬\n";
}


int climbing(object me)
{
        if( !query_temp("redlworkroom/step", me) )
                set_temp("redlworkroom/step", 1, me);

        switch(query_temp("redlworkroom/step", me) )
        {
        case 1:
                        message_vision(YEL + "$N提腳沿土路往山坡攀登。\n" + NOR, me);
                        break;
        case 2:
                        message_vision(YEL + "$N一步步地艱難地攀登翠微。\n" + NOR, me);
                        break;
        case 3:
                        message_vision(YEL + "$N三步一歇吃力地繼續往上行走。\n" + NOR, me);
                        break;
        case 4:
                        message_vision(YEL + "$N兩步一喘來到東籬院前。\n" + NOR, me);
                        break;
        default:
                        message_vision(YEL + "$N穿過籬笆走進院內站定。\n" + NOR, me);
                        return stop_climbing(me);
        }
                addn_temp("redlworkroom/step", 1, me);
        return 1;
}

int stop_climbing(object me)
{
        delete_temp("redlworkroom/step", me);
        me->set_short_desc(0);
        return 0;
}
