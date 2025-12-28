#include <ansi.h>
inherit TASK;
void create()
{
        set_name(HIW "禿鷹羽氅" NOR,({ "yu chang" }) );
        set_weight(100);
        if( clonep() )
                destruct(this_object());
        else {
                set("unit", "件");
                set("material", "cloth");
                set("long", "這是一件禿鷹羽氅。\n");
        }
        set("owner", "水笙");
        setup();
}

