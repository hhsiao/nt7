#include <ansi.h>

inherit ITEM;
int is_forging_ob() { return 1; }

void create()
{
        set_name(HIB "寒星隕鐵" NOR, ({"hanxing yuntie", "hanxing", "yuntie"}));
        set_weight(1000);
        set("long", sort_msg(HIM "從太空掉落下來的一種寒星隕鐵。"
                                         "似乎包容著不為人知的力量，但卻感覺"
                                         "不到一點能量。\n" NOR));
                set("unit", "塊");
                set("value", 20000000);
                set("item_origin", 1);
                set("material_attrib", "hanxing yuntie");
                set("material_name", HIM "寒星隕鐵" NOR);
                set("can_make", "all");
                set("power_point", 200);
}
