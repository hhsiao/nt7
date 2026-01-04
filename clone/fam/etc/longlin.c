#include <ansi.h>
inherit ITEM;

void create() {
    set_name(HIW "龍鱗" NOR, ({ "dragon palta", "palta" }));
    set_weight(2000);
    set("long", HIW "一片龍鱗，光彩奪目。\n" NOR);
    set("unit", "片");
    set("value", 100000);
    setup();
}

int query_autoload() {
    return 1;
}
