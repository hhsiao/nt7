#include <ansi.h>

inherit TESSERA;

void create() {
    set_name(HIR "九幽·神魔" NOR, ({"shen mo", "shen", "mo"}));
    set_weight(300);
    set("long", HIY "霎那間天地變色，萬物隱匿，乃魔界至高無上的寶物，支配著魔界萬物。\n" NOR);
    set("unit", "塊");
    set("value", 13000);
    set("can_be_tessera", 1);

    set("magic/type", "magic");
    set("magic/power", 1000);
    set("enchase/SN", 5 + random(5));
    set("enchase/type", "all");
    set("enchase/weapon_prop", ([
        "add_magic": 3,
        "add_skill": 30,
        "research_effect": 3,
        "practice_effect": 3,
        "derive_effect": 3
        ]));
    set("enchase/armor_prop", ([
        "reduce_magic": 1,
        "research_effect": 3,
        "practice_effect": 3,
        "derive_effect": 3
        ]));
    setup();
}

int query_autoload() {
    return 1;
}
