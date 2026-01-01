// sjping.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("四剪瓶", ({ "sijian ping", "ping" }));
        set_weight(500);
        set("unit", "個");
                set("long", "這是一個黑石瓶子，看上去聽不起眼的。\n");
                set("value", 1000);
                set("material", "stone");
        setup();
}
