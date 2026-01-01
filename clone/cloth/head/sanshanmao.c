// sanshanmao.c

#include <armor.h>
inherit HEAD;
void create()
{
        set_name("三山帽", ({ "sanshan mao", "head" }) );
        set_weight(100);
        set("unit", "頂");
                set("value",400);
                set("material", "cloth");
                set("armor_prop/armor", 1);
        setup();
}
