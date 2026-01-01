// This program is a part of NITAN MudLIB
// redl 2012/11/1

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(HIB "玉清丸" NOR, ({"yuqing wan", "wan"}));
        set("long", "這是一顆玉清丸，據說是沈芝毓從武當玉清散提純出來的增強秘藥。\n");
                set("base_unit", "顆");
                set("base_value", 150000000);
                set("base_weight", 800);
                set("only_do_effect", 1);
                set("unit", "堆");
        setup();
}

int do_effect(object me)
{
                if( query("max_jingli", me)>=me->query_current_jingli_limit() )
                {
                        return notify_fail(YEL + "你很想再吃一顆..直覺卻告訴你不會再有啥效果了...\n" + NOR);
                }

        message_vision(YEL "$N" YEL "吃下一顆" + name() +
                       YEL "，內息急轉大小周天，感覺精氣發生了一些變化。\n", me);

        addn("max_jingli", 6000+random(500), me);
        if( query("max_jingli", me)>me->query_current_jingli_limit() )
                set("max_jingli", me->query_current_jingli_limit(), me);
        // me->start_busy(3);
        add_amount(-1);
        if (query_amount() < 1)
                destruct(this_object());
        return 1;
}
