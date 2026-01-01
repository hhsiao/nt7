// Room: /d/nanyang/npc/cloth.c
// Last Modified by Lonely on Nov. 20 2001

#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("藍緞長衫", ({ "cloth" }) );
        set("long","一件紫藍色的綢面長衫，穿起來很氣派。\n");
        set_weight(1000);
        set("unit", "件");
                set("material", "cloth");
                set("value",1000);
                set("no_get",1);
                set("armor_prop/per",1);
                set("armor_prop/armor", 1);
        setup();
}
