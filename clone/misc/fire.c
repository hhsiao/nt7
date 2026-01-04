// /clone/misc/fire.c
// Last Modified by Lonely on May. 15 2001

inherit ITEM;

void create() {
    set_name("火折", ({"fire", "huozhe"}));
    set_weight(80);
    set("long", "這是一支用於引火的火折，到了黑暗的地方就用(use)得著了。\n");
    set("unit", "支");
    set("value", 100);
}
