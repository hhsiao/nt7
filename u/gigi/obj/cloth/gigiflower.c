// gigiflower.c  ^_^

#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(HIW"月朦朧"NOR, ({ "pear flower", "head" }) );
        set_weight(100);
        set("unit", "朵");
                 set("long","這是一朵潔白的梨花，花瓣皎潔如月，\n正如詩中所吟:“月朧朧，一樹梨花細雨中。”\n");
                set("value",0);
                set("material", "cloth");
                set("armor_prop/armor", 1);
        setup();
}
