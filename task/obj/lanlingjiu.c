
#include <ansi.h>
inherit TASK;
void create()
{
    set_name( HIW "蘭陵酒" NOR, ({ "lanling jiu" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "壺");
            set("material", "stone");
            set("long", "這是一壺蘭陵酒。\n");
          }
    set("owner", "李白");
    setup();
}

