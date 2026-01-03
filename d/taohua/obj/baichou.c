// baichou.c
inherit EQUIP;
void create() {
    set_name("白綢裙", ({ "baichou qun", "qun" }) );
    set_weight(500);
    set("unit", "件");
    set("armor_type", "cloth");
    set("value", 5000);
    set("armor_prop/dodge", 5);
    set("armor_prop/armor", 2);
}
