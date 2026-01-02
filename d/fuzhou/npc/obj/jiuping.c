// jiuping.c
#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create() {
    set_name(GRN"酒瓶"NOR, ({"jiuping", "bottle"}));
    set_weight(700);
    set("long", "一個晶瑩碧綠的的大酒瓶，裝了熏熏醉人的福建老酒。\n");
    set("unit", "個");
    set("value", 200);
    set("max_liquid", 15);
    set("liquid", ([
        "type": "alcohol",
        "name": "福建老酒",
        "remaining": 15,
        "drunk_apply": 3
        ]));
}
