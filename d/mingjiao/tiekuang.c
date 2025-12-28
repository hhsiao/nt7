// Code of JHSH
// Room: /d/mingjiao/luanshidui.c
// Zhangchi 3/00

#include <ansi.h>
inherit ROOM;

int start_wa(object me);
int check_busy(object me);

void create()
{
        set("short",HIR "鐵礦" NOR);
        set("long", @LONG
[1；37m這裡是一個光禿禿的小山丘，四周什麼花草樹木也沒有。仔細一
看，發現山丘周圍有些黑黝黝的大石頭，這就是光明頂盛產的烏金鐵
礦石。明教教眾用的兵器都是用這種礦石鑄造而成，比之尋常精鐵鑄
造的兵器更為堅固，鋒利。[2；37；0m
LONG );
        set("exits", ([ /* sizeof() == 1 */
          "east" : __DIR__"rjqmenlou1",
        ]));

        set("invalid_startroom", 1);
        set("wa_times",15);
        setup();

}

void init()
{
        add_action("do_save", "save");
        add_action("do_wa", "excavate");
        add_action("do_wa", "dig");
}

int do_save(string arg)
{
        write("這裡並非一般地方,不能在這裡紀錄。\n");
        return 1;
}

int do_wa(string arg)
{
        object qiao,me;

        me = this_player();

        if( me->is_busy() || query_temp("pending/job_busy", me) )
                return notify_fail("你正忙著呢。\n");

        if( query("mingjiao/job", me) != "jin_caikuang")
                return notify_fail("這裡不能隨便亂挖！\n");

        if( present("wujin kuangshi", me) )
                return notify_fail("你已經有一塊礦石，實在抱不動第二塊了。\n");

        if( !objectp(qiao = present("tie qiao", me)) )
                 return notify_fail("你沒有趁手的工具，無法開採鐵礦\n");

        if( query("jing", me) < 50 || query("qi", me) < 30 )
                return notify_fail("你已經精疲力竭了！\n");

        if( query("wa_times") > 0 )
        {
                message_vision("$N將鐵鍬拿在手上，看準了一塊黑黝黝的烏金鐵礦石，用力向下挖去。\n",me);
                set_temp("pending/job_busy", 1, me);
                call_out("start_wa", 10, me);
                me->start_busy( (: check_busy :) );
        }
        else
                tell_object(me,"礦石似乎都被挖光了。\n");

        return 1;

}

int check_busy(object me)
{
        if (query_temp("pending/job_busy", me)) return 1;
        return 0;
}

int start_wa(object me)
{
        object kuangshi;

        if(query("jingli", me)>90 && random(3)==1)
        {
                message_vision("$N將一小塊"+HIB"烏金礦石"NOR+"挖了出來放在身上。\n",me);
                addn("wa_times",-1);
                kuangshi=new(__DIR__"obj/kuangshi");
                if (! kuangshi->move(me))
                        kuangshi->move(environment(me));
                addn("jing",-20, me);
                addn("qi",-30, me);
        }
        else
        {
                tell_object(me,HIR"你突然覺得氣力不濟，怎樣也無法將那塊礦石挖出。\n"NOR);
                addn("jing",-20, me);
                addn("qi",-30, me);
        }

        delete_temp("pending/job_busy", me);
        return 1;

}

int valid_leave(object me, string dir)
{
//      object ob;

        if (dir == "northeast" && query_temp("job_busy", me) )
               return notify_fail("你正忙著挖礦呢！\n");

        return ::valid_leave(me, dir);
}