// shuinang.c  水囊

inherit ITEM;
inherit F_LIQUID;

void create() {
    set_name("水囊", ({"shuinang", "wineskin", "skin"}));
    set_weight(500);
    set("long", "這是裝滿清水的水囊。\n");
    set("unit", "只");
    set("value", 200);
    set("max_liquid", 300);

    set("liquid", ([
        "type": "water",
        "name": "天山雪水",
        "remaining": 10,
        "drunk_apply": 30
        ]));
}
