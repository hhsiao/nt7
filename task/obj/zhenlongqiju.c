
#include <ansi.h>
inherit TASK;
void create()
{
    set_name( HIW "珍瓏棋局" NOR, ({ "zhenlong qiju" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "本");
            set("material", "paper");
            set("long", "這是一本珍瓏棋局。\n");
          }
    set("owner", "虛竹子");
    setup();
}

