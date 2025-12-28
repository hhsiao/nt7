
#include <ansi.h>
inherit TASK;
void create()
{
    set_name( HIR "血紅花兒" NOR, ({ "blood flower" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "朵");
            set("material", "wood");
            set("long", "這是一朵血紅花兒。\n");
          }
    set("owner", "沈芝毓");
    setup();
}

