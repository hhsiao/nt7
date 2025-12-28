#include <ansi.h>
inherit TASK;
void create()
{
        set_name(HIY "黃內褲" NOR,({ "huang neiku" }) );
        set_weight(100);
        if( clonep() )
                destruct(this_object());
        else {
                set("unit", "件");
                set("material", "cloth");
                set("long", "這是一件皇帝穿過的黃內褲。\n");
        }
        set("owner", "韋小寶");
        setup();
}

