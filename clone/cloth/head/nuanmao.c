// nuanmao.c

#include <armor.h>
inherit HEAD;
void create()
{
        set_name("遮塵暖帽", ({ "nuan mao", "head" }) );
        set_weight(100);
        set("unit", "頂");
                set("value",150);
                set("material", "cloth");
                set("armor_prop/armor", 1);
        setup();
}
