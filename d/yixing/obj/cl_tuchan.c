// /d/yixing/obj/tuchan.c
// Last Modified by Lonely on Jul. 12 2002

inherit ITEM;

void create() {
    set_name("關東土產", ({ "tuchan" }));
    set("weight", 200);
    set("long", "這是一包關東土產。\n");
    set("unit", "包");
    set("material", "wood");
    set("value", 300);
    setup();
}
