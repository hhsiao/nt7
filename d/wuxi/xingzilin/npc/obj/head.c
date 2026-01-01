// This program is a part of NITAN MudLIB
// redl 2012/11/1
#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name(HIR"惡人首級"NOR, ({ "head" }));
        set("long", NOR + WHT "這是一枚在杏子林裡砍下的四大惡人的首級。\n" NOR);
                set("base_unit", "枚");
                set("base_value", 1000);
                set("base_weight", 300);
                set("unit", "堆");
        //set("maze_item", 1);
        //set("no_get", 1);
        //set("no_put", 1);
        //set("no_give", 1); //可以讓大米去做本任務, ../的beggar.c裡限制了可完成的主id等級
        set("no_sell", "這可是血淋淋的人頭啊...\n");
        set("no_put", "這可是血淋淋的人頭啊...\n");//不能放進乾坤袋，方便別人可以搶劫
                set("set_data", 1); //下線不掉，因為杏子林深處可能無法走路去老乞丐，只能quit
                set("auto_load", 1);
        set("xzz/headlv", 1);
        setup();
        set_amount(1);
}
