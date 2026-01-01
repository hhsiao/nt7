// /d/yixing/obj/biaohuo.c
// Last Modified by Lonely on Jul. 12 2002

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(RED"紅鏢"NOR, ({"hong biao", "biao"}));
        set("weight", 20);
        set("long", "這是一份紅鏢，包裝非常仔細，不知裝著什麼東西。\n");
                set("unit", "份");
                set("value", 30);
        setup();
}
