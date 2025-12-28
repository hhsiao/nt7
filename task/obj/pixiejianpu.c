#include <ansi.h>
inherit TASK;
void create()
{
        set_name(HIC "辟邪劍譜" NOR,({ "pixie jianpu" }) );
        set_weight(100);
        if( clonep() )
                destruct(this_object());
        else {
                set("unit", "本");
                set("material", "paper");
                set("long", "這是一本辟邪劍普秘籍。\n");
        }
        set("owner", "林平之");
        setup();
}  
