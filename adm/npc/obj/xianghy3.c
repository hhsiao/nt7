// This program is a part of NITAN MudLIB 
// redl 2013/3
#include <ansi.h>
inherit BAOXIANG_ITEM;

void create()
{
        set_name(HIW"江湖"HIY"寶箱"NOR,({"xiang"}));
        //這個一定要設置：
        set("BAOXIANG_LIST",([
                                "/clone/money/gold"                                     :200,
                                "/clone/money/cash"                                     :50,
                "/clone/medicine/yuqing"                        :250,
                "/clone/fam/etc/prize5"                         :105,
                "/clone/gift/puti-zi"                           :58,
                                "/clone/tessera/rune11"                         :9,
                                "/clone/tessera/rune12"                         :9,
                                "/clone/tessera/rune13"                         :9,
                                "/clone/tessera/rune14"                         :9,
                                "/clone/tessera/rune15"                         :9,
                "/clone/gift/jiuzhuan"                          :80,
                                "/clone/tessera/rune20"                         :3,
                                "/clone/tessera/rune21"                         :3,
                                "/clone/tessera/rune22"                         :3,
                                "/clone/tessera/rune23"                         :3,
                                "/clone/tessera/rune24"                         :3,
                "/clone/gift/tianxiang"                         :9,
                                "/clone/goods/tianshi-charm"            :2,
                "/clone/gift/xuanhuang"                         :5,
                "/clone/tessera/diamond"                :4,
                "/clone/tessera/emerald"                :4,
                "/clone/tessera/sapphire"               :4,
                "/clone/tessera/ruby"                   :4,
                "/clone/tessera/topaz"                  :4,

                
        ])); //概率是以1000作為總數，且幾項的概率總和為1000，概率大的出現幾率高。。。
        
        set("long", HIY "這是寶寶在江湖遊歷時獲取到的箱子，裝飾的珠光寶氣，你或許可以打開（open）它。\n" NOR); 
        set("unit", "些");
        set("base_unit", "個");
                set("dynamic_quest", 1);
                set("no_sell", "這樣東西不能離開你。\n");
                set("no_store", "這樣東西不能放在那兒。\n");
                set("no_steal", "這樣東西不能離開那兒。\n");
                set("no_beg", "這樣東西不能離開那兒。\n");
                set("base_value", 100);
                        set("base_weight",1);
        set_amount(1); //因為是個combined物品 所以這個一定要設置，不然報錯的

}
void init()
{
        add_action("do_open","open"); //玩家使用的接口 具體內容在std裡
        //add_action("do_test","test"); //用於巫師測試用 測試ok請註釋此行
}

