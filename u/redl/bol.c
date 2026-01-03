// This program is a part of NITAN MudLIB
// redl 2012/11/1
#include <ansi.h>
inherit ITEM;

void create()
{
              set_name(HIC"鵲橋"NOR, ({"bridge oflove", "bridge"}) );
              set_weight(1);
                      set("long", "這是Redl給愛妻Gigi的專用通道，閒人莫能enter bridge！\n");
                      set("unit", "道");
                      set("value", 10000);
                      set("no_get",1);
              setup();
}

void init()
{
              add_action("do_enter","enter");
}

int do_enter(string arg)
{
                object me = this_player();
                string id = query("id", me);

                        if (! arg || (arg != "bridge" && arg != "bridge oflove" && arg != "鵲橋"))
                                return 0;

                        if(me->is_busy()) return 1;

                if (id != "gigi" && id != "redl") {
                        tell_object(me, NOR "你感覺鵲橋神秘莫測，猶豫中竟不敢往前踏足半步！\n" NOR);
                                me->start_busy(1);
                        return 1;
                }

                message_vision(NOR"$N輕輕移步踏上" + HIC"鵲橋"NOR + "。\n" + "一道" + HIW + BRED"七" + BGRN"彩" + BYEL"斑" + BBLU"斕" + BRED"的" + BMAG"霓" + BCYN"虹" + NOR"平地升起，\n託在$N的足下往九天之外飛去...\n", me);
                me->move("/u/redl/workroom");
                message_vision(NOR "$N輕輕移步走下" + HIC"鵲橋" + NOR + "。\n", me);
                tell_object(me, NOR "(要收起來輸入：y)\n" NOR);
                        input_to("get_bridge", me);
            return 1;
}
protected void get_bridge(string fun, object me)
{
            switch (fun)
        {
        case "y":
        case "Y":
                        tell_object(me, HIC"鵲橋"NOR + "化作一點星芒閃電撲入你懷中。\n" NOR);
                        this_object()->move(me, 1);
                return;
        default:
                return;
        }
}
