#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(NOR + MAG "紫蛟筋" NOR, ({ "dragon vein", "vein" }));
        set_weight(4000);
        set("long", NOR + MAG "一根南海惡蛟的龍筋，呈紫黑色。\n" NOR);
                set("unit", "根");
                set("value", 500000);
        setup();
}

int query_autoload()
{
        return 1;
}
