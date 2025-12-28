
#include <ansi.h>
inherit TASK;
void create()
{
    set_name( HIC "青花瓷碗" NOR, ({ "qinghua ciwan" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "個");
            set("material", "stone");
            set("long", "這是一個青花瓷碗。\n");
          }
    set("owner", "曲三");
    setup();
}

