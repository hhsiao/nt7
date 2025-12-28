
#include <ansi.h>
inherit TASK;
void create()
{
    set_name( HIW "徐霞客遊記" NOR, ({ "xxk youji" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "本");
            set("material", "paper");
            set("long", "這是一本徐霞客遊記。\n");
          }
    set("owner", "徐霞客");
    setup();
}

