// budd_staff.c
// Last Modified by Lonely on May. 25 2001

#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
         set_name( HIY "黃銅禪杖" NOR, ({ "huangtong chanzhang", "staff" }) );
         set_weight(10000);
         set("unit", "條");
                 set("long", "一條又粗又長，非常沉重的黃銅禪杖，上面鑲著六個銅環。\n");
                 set("value", 10000);
                 set("material", "brass");
                 set("wield_msg", "$N拿出一根金光燦然的$n握在手中。\n");
                 set("unwield_msg", "$N放下手中的$n。\n");

         init_staff(36);
         setup();
}
