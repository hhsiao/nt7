//wrists.c

#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create() {
    set_name(HIY"鎏金腕鏈"NOR, ({ "liujin wanlian", "wanlian", "wrists" }));
    set("weight", 200);
    set("unit", "個");
    set("value", 5000);
    set("material", "gold");
    set("armor_prop/armor", 1);

    setup();
}
