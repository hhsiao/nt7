// liyu.c 鯉魚

inherit ITEM;

#include <ansi.h>
#include "fish.h"

void create()
{
        set_name("鯉魚", ({ "liyu", "li yu" }) );
        set("long", "一條活蹦亂跳的大鯉魚。\n");
                set("unit", "條");

        setup();
}
