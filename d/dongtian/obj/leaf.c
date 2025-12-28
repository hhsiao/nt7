// This program is a part of NITAN MudLIB 
// redl 2015/3
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(NOR HIC"仙隱"HIG"符葉"NOR,({"xianyin fuye", "fuye"}));
        set("long", HIG "這是一片仙界流傳出來的神奇樹葉，上面刻畫有隱身符意。\n" NOR HIK "(use fuye)\n" NOR); 
        set("unit", "片");
        set("base_unit", "片");
        set("value", 10000);
        set("base_value", 10000);
        set_weight(100);
        set("base_weight",100);
        set("material", "jade");
        setup();
}

int do_open(string arg)
{
        object ob, me = this_player();
        int ra, lv = query("level", me);
                
                if (environment()!=me) return 0;
        if (!arg || (arg!="fuye" && arg!="xianyin fuye")) return 0;
        if( me->is_busy() ||
                me->is_fighting()
                ) {
                write(NOR BUSY_MESSAGE NOR);
                return 1;
        }
        if (lv<50) {
                write(NOR "你的等級小於５０級，不能使用這種符葉。\n" NOR);
                return 1;
        }
        if (query_temp("flag_hslj", me)) {
                write(NOR "現在是在華山擂臺，不能使用這種符葉。\n" NOR);
                return 1;
        }
        if( query_temp("apply/shade_vision", me) ) {
                        write(NOR "你現在正在隱身之中。\n" NOR);
                return 1;
                }
                if( me->is_fighting()) {
                        write(NOR "你還是專心解決了敵人再說吧。\n" NOR);
                return 1;
                }
        set_temp("apply/shade_vision", 1, me);
        me->start_busy(3);
        message_vision(NOR + CYN + "$N" + NOR + CYN + "拿出一個樹葉，抬手望自己額頭上一帖，身形快速地消失了。\n" + NOR, me);
                __DIR__"leaf_c.c"->do_remove_yinxian(me);
        destruct(this_object());
        return 1;
}

void init()
{
        add_action("do_open","use"); 
}

