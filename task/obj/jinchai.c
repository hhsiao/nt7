#include <ansi.h>
inherit TASK;
void create()
{
        set_name(HIY "金釵" NOR,({ "jin chai" }) );
        set_weight(100);
        if( clonep() )
                destruct(this_object());
        else {
                set("unit", "個");
                set("material", "stone");
                set("long", "這是個造型獨特的金釵。\n");
        }
        set("owner", "王語嫣");
        setup();
}

