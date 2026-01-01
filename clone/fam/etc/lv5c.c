inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(YEL "天罡碳" NOR, ({"tiangang tan", "tiangang", "tan"}));
        set_weight(300);
        set("long", YEL "埋藏於極地中心的烏炭，可煉化世間萬物。\n" NOR);
                set("unit", "塊");
                set("value", 15000);
        setup();
}

int query_autoload()
{
        return 1;
}
