// guanyinchabei.c
// Last Modified by Lonely on May. 29 2001

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("鐵觀音茶杯",({"guanyin chabei", "cha", "chabei"}));
        set_weight(120);
        set("long", "一杯新沏的鐵觀音茶，悠悠地冒著香氣~~~~~~\n");
                set("unit", "杯");
                set("value", 40);
                set("remaining",10);
                set("drink_supply", 20);
        set("liquid", ([
                "type": "tea",
                "name": "茶",
                "remaining": 15,
                "drunk_apply": 5,
        ]));
}
