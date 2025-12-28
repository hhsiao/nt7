
#include <ansi.h>
inherit TASK;
void create()
{
    set_name( HIG "七心海棠" NOR, ({ "qixin haitang" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "個");
            set("material", "wood");
            set("long", "這是一個七心海棠。\n");
          }
    set("owner", "程靈素");
    setup();
}

