inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIW "如意通天钁" NOR, ({"ruyi jue", "ruyi", "jue"}));
        set_weight(300);
        set("long", HIW "純白無暇的寶玉，傳說只有在天界才會出現。\n" NOR);
                set("unit", "塊");
                set("value", 50000);
                set("can_be_enchased", 1);
                set("magic/type", "cold");
                set("magic/power", 50);
        setup();
}

int query_autoload()
{
        return 1;
}
