// qhcwan.c  青花瓷碗

inherit ITEM;
inherit F_LIQUID;

void create() {
    set_name("缺口的青花瓷碗", ({"qinghua ciwan", "wan", "ciwan"}));
    set_weight(100);
    set("long", "一個缺了口的粗瓷碗。\n");
    set("unit", "個");
    set("value", 100);
    set("max_liquid", 15);
    set("liquid", ([
        "type": "alcohol",
        "name": "清水",
        "remaining": 15,
        "drunk_apply": 3
        ]));
}
