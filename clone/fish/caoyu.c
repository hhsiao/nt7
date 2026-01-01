// caoyu.c 草魚

inherit ITEM;

#include <ansi.h>
#include "fish.h"

void create()
{
        set_name("草魚", ({ "caoyu", "cao yu" }) );
        set("long", "一條活蹦亂跳的草魚。\n");
                set("unit", "條");

        setup();
}
