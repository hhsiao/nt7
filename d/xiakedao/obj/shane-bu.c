// shane-bu.c 賞善罰惡簿

#include <armor.h>
#include <ansi.h>

inherit NECK;

void create() {
    set_name("賞善罰惡簿", ({ "shane bu", "bu" }));
    set("long", "這是一本賞善罰惡簿，裡頭記載著江湖善惡。\n");
    set("weight", 300);
    set("unit", "本");
    set("value", 500);
    set("material", "paper");
    setup();
}
