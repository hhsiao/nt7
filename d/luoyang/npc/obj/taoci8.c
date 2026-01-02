#include <ansi.h>
inherit ITEM;

void create() {
    set_name(HIB "碧海青天爵" NOR, ({ "qingtian jue", "qingtian", "jue" }) );
    set_weight(5000);
    set("unit", "只");
    set("long", HIB "經唐三彩燒製的碧海青天爵，非常的昂貴。\n" NOR);
    set("value", 1500);
}
