//baipao.c
#include <armor.h>

inherit CLOTH;

void create() {
    set_name("白色長袍", ({ "chang pao", "cloth", "pao" }) );
    set_weight(2000);
    set("unit", "件");
    set("long", "這是件質量上佳的白色長袍。\n");
    set("material", "cloth");
    set("armor_prop/armor", 7);
    set("value", 100);
    setup();
}
