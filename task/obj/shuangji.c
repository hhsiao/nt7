
#include <ansi.h>
inherit TASK;
void create()
{
    set_name( HIW "短柄雙戟" NOR, ({ "duanbing shuangji" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "把");
            set("material", "steel");
            set("long", "這是一把短柄雙戟。\n");
          }
    set("owner", "郭嘯天");
    setup();
}

