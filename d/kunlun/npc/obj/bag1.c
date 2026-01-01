// bag.c
#include <ansi.h>;
inherit ITEM;

void create() {
    set_name("油布包", ({ "bag", "bao" }));
    set_weight(200);
    set("unit", "個");
    set("long", "這是一個油布包裹。\n");
    set("value", 500);
    set("material", "cloth");
    set("book_count", 1);
}

void init() {
    if(this_player() == environment() )
    {
        add_action("do_open", "open");
        add_action("do_open", "unpack");
        add_action("do_open", "dakai");
    }
}

int do_open(string arg) {

    if (!arg ) return 0;
    return notify_fail("油布包裡面什麼也沒有了。\n");
}
