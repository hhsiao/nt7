// dish.c 菜餚

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("菜餚", ({ "dish" }));
        set_weight(40);
        set("unit", "份");
                set("remaining", 5);
                set("drink_supply", 15);
             set("liquid", ([
                     "type": "soup",
                     "name": "湯",
                     "remaining": 15,
                     "drunk_apply": 3,
             ]));
}
