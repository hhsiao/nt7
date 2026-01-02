// jiunang.c  大酒囊

inherit ITEM;
inherit F_LIQUID;

void create() {
    set_name("大酒囊", ({"jiunang", "wineskin", "skin"}));
    set_weight(700);
    set("long", "一隻是草原牧民的大酒囊，裡面裝滿了香辣的馬奶酒。\n");
    set("unit", "只");
    set("value", 250);
    set("max_liquid", 400);

    set("liquid", ([
        "type": "alcohol",
        "name": "馬奶酒",
        "remaining": 10,
        "drunk_apply": 40
        ]));
}
