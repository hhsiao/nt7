
#include <weapon.h>
#include <ansi.h>
inherit TASK;
void create()
{
        set_name( CYN"玉簫" NOR,({ "yu_xiao" }));
        set_weight(10000);
        set("unit", "只");
        set("long","一隻晶瑩透亮的玉簫。拿在手裡。滑膩膩的。上面刻著幾個字\n"
					HIM"\t\t盈盈送\n"NOR);
        set("value", 10000);
        set("material", "異類金屬");
        set("wield_msg", "$N從懷裡摸出一隻$n作為武器。\n");
        set("unwield_msg", "$N將手中的$n放入懷裡。\n");
        set("owner","令狐沖");
		set("task",1);
        set("no_put_in",1);

        setup();
}
