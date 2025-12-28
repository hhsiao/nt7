
#include <ansi.h>
inherit TASK;
void create()
{
    set_name( HIC "斷魂膏" NOR, ({ "duanhun gao" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "貼");
            set("material", "wood");
            set("long", "這是一貼斷魂膏。\n");
          }
    set("owner", "閻基");
    setup();
}

