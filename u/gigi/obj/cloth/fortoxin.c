// gigiflower.c  ^_^

#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(YEL"一大坨便便"NOR, ({ "shit for toxin", "head" }) );
        set_weight(100);
        set("unit", "坨");
                 set("long","這是鬍子長的"+YEL"一大坨便便"NOR+"。\n");
                set("wear_msg", NOR "$N悄悄從身後掏出" YEL "一大坨便便" NOR "頂在頭上。\n" NOR);
                set("remove_msg", NOR "$N輕輕地把頭上" YEL "一大坨便便" NOR "又塞進褲襠裡。\n" NOR);
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
