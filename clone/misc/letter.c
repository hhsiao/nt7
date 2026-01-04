#include <ansi.h>
inherit ITEM;

int is_letter() { return 1; }

void create() {
    set_name(NOR + WHT "信件" NOR, ({ "letter" }));
    set("unit", "封");
    set("long", "這是一封信件。\n");
    set("value", 0);
    setup();
}
