#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIY "金環鎖子甲" NOR, ({ "suozi jia", "jia"}) );
        set_weight(20000);
        set("unit", "件");
                set("value", 300000);
                set("material", "leather");
                set("armor_prop/armor", 200);
        setup();
}

void owner_is_killed()
{
        destruct(this_object());
}
