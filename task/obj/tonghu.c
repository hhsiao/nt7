
#include <ansi.h>
inherit TASK;
void create()
{
    set_name( YEL "大銅茶壺" NOR, ({ "tong hu" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "個");
            set("material", "steel");
            set("long", "這是一個大銅茶壺。\n");
          }
    set("owner", "龜公");
    setup();
}

