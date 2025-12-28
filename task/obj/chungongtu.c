#include <ansi.h>
inherit TASK;
void create()
{
        set_name(HIR "春宮圖" NOR,({ "chungong tu" }) );
        set_weight(100);
        if( clonep() )
                destruct(this_object());
        else {
                set("unit", "本");
                set("material", "paper");
                set("long", "這是一本宮廷流傳出來的春宮圖。\n");
        }
        set("owner", "韋春芳");
        setup();
}
