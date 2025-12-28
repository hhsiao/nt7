
#include <ansi.h>
inherit TASK;
void create()
{
    set_name( HIW "藏寶圖" NOR, ({ "cangbao tu" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "張");
            set("material", "paper");
            set("long", "這是一張藏寶圖。\n");
          }
    set("owner", "淩退思");
    setup();
}

