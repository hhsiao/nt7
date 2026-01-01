// gigiflower.c  ^_^

#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(YEL"一大坨便便"NOR, ({ "shit for dcgz", "cloth" }) );
        set_weight(100);
        set("unit", "坨");
                 set("long","這是大腸乾燥的"+YEL"一大坨便便"NOR+"。\n");
                set("wear_msg", NOR "$N悄悄從身後掏出" YEL "一大坨便便" NOR "抹在身上。\n" NOR);
                set("remove_msg", NOR "$N手腳並用地把身上" YEL "一大坨便便" NOR "揉成一團塞進褲襠裡。\n" NOR);
                set("value",0);
                set("material", "cloth");
                set("armor_prop/armor", 1);
            set("enchase", ([
                      "apply_prop" : ([ /* sizeof() == 2 */
                              "per" : -25,
                              "int" : -25,
                      ]),
             ]));

        setup();
}
