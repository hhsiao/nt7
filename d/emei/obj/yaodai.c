// huyao.c

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create() {
    set_name("皮腰帶", ({ "yao dai", "yaodai" }) );
    set_weight(300);
    set_max_encumbrance(1000);
    set("unit", "條");
    set("long", "這是一件皮質的寬腰帶，夾層透空，可以放各種軟兵刃。\n");
    set("value", 6000);
    set("material", "waist");
    set("armor_prop/armor", 5);
    setup();
}

int is_container() { return 1; }
