#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW "聖騎士勳章" NOR, ({ "chivalry medal", "chivalry", "medal" }));
        set_weight(1000);
        set("long", HIW "英國女王頒發的獎章，似乎可以賣個好價錢。\n" NOR);
                set("unit", "枚");
                set("value", 500000);
        setup();
}
