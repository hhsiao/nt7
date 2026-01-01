// metal.c 精金

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW "精金" NOR, ({ "jing jin", "metal" }) );
        set_weight(30);
        set("long", HIW "這是一枚精金，由西方庚辛之氣凝結而成，色銀白，堅不可摧。\n" NOR);
                set("value", 2000);
                set("unit", "枚");
                set("magic/element", "metal");
        setup();
}
