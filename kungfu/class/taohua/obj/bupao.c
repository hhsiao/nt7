// bupao.c

inherit EQUIP;

void create() {
    set_name("青布袍", ({ "qing bupao", "bupao", "pao", }) );
    set_weight(1000);
    set("unit", "件");
    set("armor_type", "cloth");
    set("value", 2500);
    set("armor_prop/dodge", 6);
    set("armor_prop/armor", 1);
}
