inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIM "《櫻花贊》" NOR, ({"yinghua zan", "yinghu", "zan"}));
        set_weight(2000);
        set("unit", "本");
                set("long", HIM "這是一本寫有《櫻花贊》的曲譜。\n"  NOR);

                set("value", 500000);
        setup();
}

int query_autoload()
{
        return 1;
}
