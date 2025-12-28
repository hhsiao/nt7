
#include <ansi.h>
inherit TASK;
void create()
{
    set_name( HIY "大漢錦囊" NOR, ({ "jin nang" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "個");
            set("material", "cloth");
            set("long", "這是一個大漢錦囊。\n");
          }
    set("owner", "李萍");
    setup();
}

