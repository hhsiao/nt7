#include <ansi.h>
inherit ITEM;

void create() {
    set_name(WHT "七竅墨雲鬥" NOR, ({ "moyun dou", "moyun", "dou" }) );
    set_weight(5000);
    set("unit", "只");
    set("long", WHT "經唐三彩燒製的七竅墨雲鬥，非常的昂貴。\n" NOR);
    set("value", 1500);
}
