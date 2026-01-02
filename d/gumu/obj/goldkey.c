// Room: /d/gumu/obj/goldkey.c
// Last Modifyed by Lonely on Jan. 14 2002

#include <ansi.h>
inherit ITEM;

void create() {
    set_name(HIY"金鑰匙"NOR, ({"jin yaoshi", "gold key", "key"}));
    set_weight(10);
    set("unit", "把");
    set("long", "這是一把黃金鑰匙，金光閃閃的，似乎和古墓的某些秘密有關。\n");
    set("value", 1000);
    setup();
}
