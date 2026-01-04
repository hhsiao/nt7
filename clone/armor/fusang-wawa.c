#include <armor.h>
#include <ansi.h>

inherit MYHEART2;

void create() {
    set_name(HIC "扶桑娃娃" NOR, ({ "fusang wawa", "fusang", "wawa" }) );
    set_weight(1);
    set("material", "paper");
    set("unit", "個");
    set("long", HIC "一個製作精美的布娃娃，扶桑武士多用此作為護身符，以求平安。\n" NOR);
    set("value", 1000000);
    set("limit", ([
        "exp": 2000000
        ]));
    set("armor_prop/fy", 1);
    setup();
}

int query_autoload() {
    return 1;
}
