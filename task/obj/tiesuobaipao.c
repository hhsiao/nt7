
#include <ansi.h>
inherit TASK;
void create()
{
    set_name( HIW "鐵索白袍" NOR, ({ "tiesuo baipao" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "件");
            set("material", "cloth");
            set("long", "這是一件鐵索白袍。\n");
          }
    set("owner", "餘滄海");
    setup();
}

