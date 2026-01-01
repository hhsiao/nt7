inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIC "青魚牙" NOR, ({"qingyu ya", "qingyu", "ya"}));
        set_weight(300);
        set("long", HIC "內蘊一條小魚的瑪瑙，可謂價值連城。\n" NOR);
                set("unit", "只");
                set("value", 15000);
        setup();
}

int query_autoload()
{
        return 1;
}
