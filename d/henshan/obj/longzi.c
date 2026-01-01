#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY "籠子" NOR, ({ "long zi","long", "zi" }));
        set_weight(1000);
        set("unit", "個");
                set("long", "這個籠子不太大，看來只能裝(zhuang)下較小的動物。 \n");
                set("value", 100);
                set("material", "iron");

        setup();
}
