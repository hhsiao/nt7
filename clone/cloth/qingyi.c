// qingyi.c

inherit EQUIP;

void create()
{
        set_name("青布袍", ({ "bupao","pao", }) );
        set("long","這是一件質地上佳的青衣。\n");
        set_weight(1000);
        set("unit", "件");
                set("armor_type", "cloth");
                set("value", 2500);
                set("armor_prop/dodge", 6);
                set("armor_prop/armor", 1);
}
