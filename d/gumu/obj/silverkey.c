// Room: /d/gumu/obj/silverkey.c
// Last Modifyed by Lonely on Jan. 14 2002

#include <ansi.h>;
inherit ITEM;

void create() {
    set_name(HIW"銀鑰匙"NOR, ({"yin yaoshi", "silver key", "key"}));
    set_weight(10);
    set("unit", "把");
    set("long", "這是一把白銀打製的鑰匙，上書古墓字樣，似乎和古墓的某些秘密有關。\n");
    set("value", 400);
    setup();
}
