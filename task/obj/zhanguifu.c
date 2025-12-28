
#include <ansi.h>
inherit TASK;
void create()
{
    set_name( HIY "天師斬鬼符" NOR, ({ "zhangui fu" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "張");
            set("material", "paper");
            set("long", "這是一張天師斬鬼符。\n");
          }
    set("owner", "張天師");
    setup();
}

