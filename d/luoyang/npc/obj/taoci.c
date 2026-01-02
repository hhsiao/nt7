#include <ansi.h>
inherit ITEM;

void create() {
    set_name(HIC "翡翠鼻菸壺" NOR, ({ "biyan hu", "biyan", "biyan" }) );
    set_weight(5000);
    set("unit", "只");
    set("long", HIC "陶瓷燒得便如翡翠一般，以此陶瓷所制的鼻菸壺。\n" NOR);
    set("value", 1500);
}
