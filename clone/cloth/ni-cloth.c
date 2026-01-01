// ni-cloth.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>;
#include <ansi.h>;

inherit CLOTH;

string* clothname = ({
        HIB"青布緇衣"NOR,
        HIC"灰布緇衣"NOR,
        HIY"粗布緇衣"NOR,
});
string* clothid = ({
        "zi yi",
        "zi yi",
        "zi yi",
});
string* clothlong = ({
        "這是一件出家人穿的青布緇衣。\n",
        "這是一件出家人穿的灰布緇衣。\n",
        "這是一件出家人穿的粗布緇衣。\n",
});

void create()
{
        int i = random(sizeof(clothname));

        set_name(clothname[i], ({ clothid[i], "cloth" }));
        set_weight(1000);
        set("long", clothlong[i]);
        //        set("long", clothlong[i]);
                set("unit", "件");
                set("value", 0);
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("armor_prop/per", 3);
                set("female_only", 1);
        setup();
}
