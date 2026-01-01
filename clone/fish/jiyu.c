// jiyu.c 鯽魚

inherit ITEM;

#include <ansi.h>
#include "fish.h";

void create()
{
        set_name("鯽魚", ({ "ji yu", "jiyu" }) );
        set("long", "一條活蹦亂跳的大鯽魚。\n");
                set("unit", "條");

        setup();
}
