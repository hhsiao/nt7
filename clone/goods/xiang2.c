
#include <ansi.h>
inherit BAOXIANG_ITEM;

void create()
{
        set_name(HIM"神秘箱子"NOR,({"xiang"}));
        //這個一定要設置：
        set("BAOXIANG_LIST",([
                "/d/emei/obj/pantao":900,   //物品文件名:概率
                "/clone/fam/max/zaohua":100,   //物品文件名:概率
        ])); //概率是以1000作為總數，且幾項的概率總和為1000，概率大的出現幾率高。。。
        
        set("long", HIY "這是一隻金色的寶箱，上面篆刻著符文，你或許可以打開（open）它。\n" NOR); 
        set("unit", "些");
        set("base_unit", "個");
        set("no_give",1);
        set("no_drop",1);
        set("base_weight",1);
        set("base_value",1);
        set_amount(1); //因為是個combined物品 所以這個一定要設置，不然報錯的

}
void init()
{
        add_action("do_open","open"); //玩家使用的接口 具體內容在std裡
        add_action("do_test","test"); //用於巫師測試用 測試ok請註釋此行
}

