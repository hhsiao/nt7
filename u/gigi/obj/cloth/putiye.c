// gigiflower.c  ^_^

#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(HIG"菩提葉"NOR, ({ "bodhi leaf", "head" }) );
        set_weight(100);
        set("unit", "片");
                 set("long","這是一片碧綠色的"+HIG"菩提葉"NOR+"，葉片色澤鮮亮且圓潤飽滿，\n似有清雅香氣傳來，令人忘卻煩憂。\n");
                set("value",0);
                set("material", "cloth");
                set("armor_prop/armor", 1);
            set("enchase", ([
                      "apply_prop" : ([ /* sizeof() == 2 */
                              "per" : 25,
                              "int" : 25,
                      ]),
             ]));

        setup();
}
