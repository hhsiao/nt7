#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIY "金盔" NOR, ({ "head" }) );
        set_weight(3000);
        set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 100);
        setup();
}
void owner_is_killed()
{
        destruct(this_object());
}
