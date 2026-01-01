inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIW "富士山風景畫" NOR, ({"fengjing hua", "fengjing", "hua"}));
        set_weight(2000);
        set("unit", "副");
                set("long", HIW "這是一副繪著富士山風景的圖畫。\n"  NOR);

                set("value", 500000);
        setup();
}

int query_autoload()
{
        return 1;
}
