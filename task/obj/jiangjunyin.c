
#include <ansi.h>
inherit TASK;
void create()
{
    set_name( HIR "平西大將軍印" NOR, ({ "jiangjun yin" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "個");
            set("material", "stone");
            set("long", "這是一個平西大將軍印。\n");
          }
    set("owner", "吳三桂");
    setup();
}

