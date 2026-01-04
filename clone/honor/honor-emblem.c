#include <ansi.h>
inherit ITEM;

void create() {
    set_name(HIY "榮譽勳章" NOR, ({ "honor emblem", "emblem" }));
    set_weight(3000);
    set("long", HIY "一枚榮譽勳章，代表至高的榮譽。\n" NOR);
    set("unit", "枚");
    set("value", 500000);
    setup();
}
