// gigiflower.c  ^_^

#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(YEL"一大堆便便"NOR, ({ "shit for rcdl", "head" }) );
        set_weight(100);
        set("unit", "堆");
                 set("long","這是綠蓮老豬的"+YEL"一大堆便便"NOR+"。\n");
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
