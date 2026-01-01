// This program is a part of NT MudLIB

#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
        set_name(BMAG "幸運女神項鍊" NOR, ({ "luck neck", "neck" }) );
        set_weight(500);
        set("unit", "個");
                set("long", HIY "這便是幸運女神戴過的項鍊，神光浮現。\n" NOR);
                set("value", 3000);
                set("no_sell", "這樣東西不能賣。\n");
                set("rigidity",8000);
                set("material", "tian jing");
                set("no_pawn", 1);
                set("armor_prop/armor", 10);

        set("mod_mark", "A3020");
        set("mod_level", "M3002");
        set("mod_name", HBRED "幸運女神之眷念" NOR);
        set("quality_level", 4);

        setup();
}
