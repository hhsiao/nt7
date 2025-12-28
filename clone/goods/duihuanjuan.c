
inherit ITEM;

#include <ansi.h>

void create()
{
        set_name(YEL "魔幻獸兌換券" NOR, ({"duihuan juan", "duihuan", "juan"}));
        set_weight(40);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/
        {
                set("long", "這是一張魔幻獸兌換券，可以拿它去狂風那裡選一個" HIM "魔幻獸。\n" NOR);
                set("unit", "張");
                set("material_attrib", "paper");
                set("value", 10000000);
                set("no_sell", 1);
        }
}

int query_autoload() { return 1; } 
