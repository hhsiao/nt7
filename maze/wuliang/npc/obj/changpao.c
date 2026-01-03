// changpao.c 長袍

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name("長袍", ({ "chang pao", "pao" ,"cloth" }) );
        set_weight(3000);
                set("unit", "件");
                set("material", "cloth");
                set("long","一件有普通布料製成的長袍。\n");
                set("value", 100);
                set("armor_prop/armor", 5);
        setup();
}
