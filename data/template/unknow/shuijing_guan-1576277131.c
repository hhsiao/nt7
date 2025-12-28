// shuijing_guan.c
// Create by TEMPLATE_D. Fri Jan 25 21:59:18 2019.
#include <armor.h>
#include <ansi.h>

inherit HEAD;
 
void create()
{
	set_name("[1;37m水晶冠[2;37;0m", ({ "shuijing guan" }));
        set_weight(1000);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/
        {
	set("material", "steel");
	set("unit", "頂");
	set("long", "[1;35m這是一頂用水晶雕琢而成的頭冠，手工精巧無比，人間罕有。
[1;36m佩帶後可提高研究及學習次數上限10%。
[2;37;0m");

	set("value", 3500000);
	set("armor_prop", ([ /* sizeof() == 2 */
  "armor" : 100,
  "yanjiu_times" : 10,
]));

	set("special", ([ /* sizeof() == 1 */
  "desc" : "[1;31m佩帶後可提高研究及學習次數上限10%。[2;37;0m",
]));
	set("require", ([ /* sizeof() == 2 */
  "int" : 30,
  "exp" : 5000000,
]));



        }
	set("armor_type", "head");
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

