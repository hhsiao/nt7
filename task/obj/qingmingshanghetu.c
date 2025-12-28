#include <ansi.h>
inherit TASK;
void create()
{
        set_name(HIW "清明上河圖" NOR,({ "qingming shanghetu" }) );
        set_weight(100);
        if( clonep() )
                destruct(this_object());
        else {
                set("unit", "張");
                set("material", "paper");
                set("long", "這是一張清明上河圖。\n");
        }
        set("owner", "馮老狗");
        setup();
}

