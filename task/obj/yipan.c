
#include <ansi.h>
inherit TASK;
void create()
{
    set_name( HIC "風水儀盤" NOR, ({ "yi pan" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "個");
            set("material", "stone");
            set("long", "這是一個風水儀盤。\n");
          }
    set("owner", "黃大仙");
    setup();
}

