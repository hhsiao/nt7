// This program is a part of NITAN MudLIB 
// redl 2013/3
#include <ansi.h>
inherit BAOXIANG_ITEM;

void create()
{
        set_name(HIC"活躍度"HIY"寶箱"NOR,({"xiang"}));
        //這個一定要設置：
        set("BAOXIANG_LIST",([
                                "/clone/money/gold"                                     :400,
                                "/clone/money/cash"                                     :50,
                "/clone/medicine/yuqing"                        :148,
                                "/clone/fam/gift/con3"                          :12,
                                "/clone/fam/gift/dex3"                          :12,
                                "/clone/fam/gift/int3"                          :12,
                                "/clone/fam/gift/str3"                          :12,
                "/clone/fam/etc/prize5"                         :100,
                "/clone/gift/puti-zi"                           :58,
                                "/clone/tessera/rune01"                         :6,
                                "/clone/tessera/rune02"                         :6,
                                "/clone/tessera/rune03"                         :6,
                                "/clone/tessera/rune04"                         :6,
                                "/clone/tessera/rune05"                         :6,
                "/clone/gift/jiuzhuan"                          :37,
                                "/clone/tessera/rune10"                         :3,
                                "/clone/tessera/rune11"                         :3,
                                "/clone/tessera/rune12"                         :3,
                                "/clone/tessera/rune13"                         :3,
                                "/clone/tessera/rune14"                         :3,
                "/clone/gift/tianxiang"                         :9,
                                "/clone/goods/tianshi-charm"            :4,
                "/clone/gift/xuanhuang"                         :1,

                
        ])); //概率是以1000作為總數，且幾項的概率總和為1000，概率大的出現幾率高。。。
        
        set("long", HIY "這是一隻華麗的箱子，裝飾的珠光寶氣，你或許可以打開（open）它。\n" NOR); 
        set("unit", "些");
        set("base_unit", "個");
                set("dynamic_quest", 1);
                        set("no_give","這樣東西不能離開你。\n");
                        set("no_drop","這樣東西不能離開你。\n");
                set("no_sell", "這樣東西不能離開你。\n");
                set("no_put", "這樣東西不能放在那兒。\n");
                set("no_store", "這樣東西不能放在那兒。\n");
                set("no_get", "這樣東西不能離開那兒。\n");
                set("no_steal", "這樣東西不能離開那兒。\n");
                set("no_beg", "這樣東西不能離開那兒。\n");
                set("base_value", 0);
                        set("base_weight",1);
        set_amount(1); //因為是個combined物品 所以這個一定要設置，不然報錯的

}
void init()
{
        add_action("do_open","open"); //玩家使用的接口 具體內容在std裡
        //add_action("do_test","test"); //用於巫師測試用 測試ok請註釋此行
}
