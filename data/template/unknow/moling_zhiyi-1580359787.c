// moling_zhiyi.c
// Create by TEMPLATE_D. Fri Jan 25 22:00:01 2019.
#include <armor.h>
#include <ansi.h>

inherit SURCOAT;

void create()
{
	set_name("[1;32m魔靈之翼[2;37;0m", ({ "moling zhiyi" }));
        set_weight(2000);
	set("long", "[1;32m這是一件形似傳說中怪鳥羽翼般的披風，看起來盛氣逼人。
[2;37;0m");
        /*if (clonep())
                set_default_object(__FILE__);
        else*/
        {
	set("unit", "件");
	set("material", "steel");
	set("value", 3000000);
	set("armor_prop", ([ /* sizeof() == 4 */
  "int" : 6,
  "dodge" : 20,
  "con" : 4,
  "armor" : 100,
]));



	set("special", ([ /* sizeof() == 1 */
  "desc" : "[1;31m提升有效輕功20級。",
]));
	set("limit", ([ /* sizeof() == 2 */
  "scborn" : 1,
  "exp" : 9000000,
]));



        }
	set("armor_type", "surcoat");
	set("no_store", 1);
	set("item_owner", "licz");
	set("no_sell", 1);
	set("stable", 37);
	set("consistence", 100);
        setup();
}

int query_autoload()
{
        return 1;
}
int receive_summon(object me)
{
        return ITEM_D->receive_summon(me, this_object());
}

// 隱藏物品
int hide_anywhere(object me)
{
        return ITEM_D->hide_anywhere(me, this_object());
}


int is_no_clone() { return 1; }

