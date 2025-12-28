
#include <ansi.h>
inherit TASK;
void create()
{
    set_name( HIW "陳圓圓畫像" NOR, ({ "hua xiang" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "張");
            set("material", "paper");
            set("long", "這是一張陳圓圓畫像。\n");
          }
    set("owner", "胡逸之");
    setup();
}

