// feicui.c 翡翠雞

inherit ITEM;
#include <ansi.h>;

void create()
{
        set_name(GRN"翡翠雞"NOR, ({ "stone chicken", "feicui ji", "ji" }));
        set("weight", 5000);
        set("unit", "對");
                set("value", 80000);
                set("long", "一對翡翠雞，一公母，雕工極是精細。\n");
                set("material", "stone");
        setup();
}
