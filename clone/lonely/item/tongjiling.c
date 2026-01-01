#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(NOR + RED "通緝令" NOR, ({ "tongji ling", "tongji", "ling" }));
        set_weight(100);
        set("long", NOR + RED "這是一張皺巴巴的通緝令，上面還帶"
                            "有隱隱血跡。\n" NOR);
                set("unit", "張");
                set("value", 10);
                set("no_sell", "官…官府的通緝令…你也敢拿來賣錢？");
                set("material", "paper");
        setup();
}
