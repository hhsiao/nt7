// baiyi.c

inherit EQUIP;

void create() {
    set_name("白絲衣", ({ "bai siyi", "siyi", }) );
    set_weight(1000);
    set("unit", "件");
    set("armor_type", "cloth");
    set("value", 2500);
    set("armor_prop/dodge", 10);
    set("armor_prop/armor", 1);
}
