#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW "白虎骨" NOR, ({ "tiger bone", "bone" }));
        set_weight(5000);
        set("long", HIW "一副白虎骨，乃製衣極品，世間罕有。\n" NOR);
                set("unit", "副");
                set("value", 500000);
        setup();
}

int query_autoload()
{
        return 1;
}
