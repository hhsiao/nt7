#include <ansi.h>
inherit TASK;
void create()
{
        set_name(HIY "金算盤" NOR,({ "jin suanpan" }) );
        set_weight(100);
        if( clonep() )
                destruct(this_object());
        else {
                set("unit", "個");
                set("material", "stone");
                set("long", "這是個金算盤。\n");
        }
        set("owner", "錢眼開");
        setup();
}

