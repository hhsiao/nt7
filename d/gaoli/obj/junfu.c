#include <armor.h>

inherit CLOTH;

void create()
{
   set_name("軍服", ({ "junfu","cloth"}) );
   set_weight(6000);
   set("material", "cloth");
     set("unit", "件");
     set("value", 60);
     set("armor_prop/armor", 20);
   setup();
}
