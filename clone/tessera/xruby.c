#include <ansi.h>

inherit TESSERA;

void create() {
    set_name(HIR "紅寶石石頭" NOR, ({ "ruby" }));
    set_weight(20);
    set("long", WHT "這是一顆寶石，上面似乎附著某種神奇的魔力。\n" NOR);
    set("value", 100000);
    set("unit", "顆");
    set("material", "ruby");
    set("no_identify", 1);
    setup();
}
