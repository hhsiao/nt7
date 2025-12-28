// longshen_toukui.c
// Create by TEMPLATE_D. Mon Mar 18 16:50:46 2019.
// toukui.c 頭盔
 
#include <armor.h>
#include <ansi.h>

inherit HEAD;
 
void create()
{
	set_name("[1;35m龍神頭盔[2;37;0m", ({ "longshen toukui" }));
        set_weight(1000);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/
        {
	set("material", "steel");
	set("unit", "頂");
	set("long", "[1;35m這是一頂龍骨鑄造的頭盔，用以保護頭部。
[2;37;0m");
	set("value", 3500000);
	set("armor_prop", ([ /* sizeof() == 1 */
  "armor" : 200,
]));
	set("limit", ([ /* sizeof() == 1 */
  "dex" : 25,
]));


        }
	set("armor_type", "head");
	set("no_store", 1);
	set("item_owner", "step");
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

