#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
    set_name("青色絲袍", ({ "si pao", "cloth", "pao" }));
    set_weight(2000);
    set("unit", "件");
    set("long", HIG "這是件質地輕柔的青色鏤花絲袍，特別受女性青睞。\n" NOR);
    set("material", "cloth");
    set("armor_prop/armor", 8);
    set("value", 100);
    setup();
}
