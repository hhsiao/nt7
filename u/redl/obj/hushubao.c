// This program is a part of NITAN MudLIB 
// redl 2014/3
#include <ansi.h>
inherit BAOXIANG_ITEM;

void create()
{
        set_name(NOR BLU"護舒寶"NOR,({"hushu bao", "bao"}));
        set("BAOXIANG_LIST",([
                                "/clone/money/thousand-gold"            :800,
                                "/clone/goods/tianshi-charm"            :130,
                                "/d/dongtian/obj/wanxiangbook"          :67,
                                "/u/redl/npc/obj/ntb"                   :3

        ])); //概率是以1000作為總數，且幾項的概率總和為1000，概率大的出現幾率高。。。
        
        set("long", NOR BLU "這是女性夜裡專用（open）物品，男童鞋拿去客店送給戚長髮處理吧。\n" NOR); 
        set("unit", "些");
        set("base_unit", "包");
                set("dynamic_quest", 1);
                set("no_sell", "這樣東西不能離開你。\n");
                set("no_store", "這樣東西不能放在那兒。\n");
                set("no_steal", "這樣東西不能離開那兒。\n");
                set("no_beg", "這樣東西不能離開那兒。\n");
                set("base_value", 100);
                set("base_weight",1);
        set("bindable", 2); 
        set_amount(1); //因為是個combined物品 所以這個一定要設置，不然報錯的

}

int cantuse()
{
        tell_object(this_player(), "你冥思苦想怎麼也得不出恰當的使用方法。\n");
        return 1;
}

void init()
{
        if (query("gender",this_player())=="女性") {
                add_action("do_open","open"); //玩家使用的接口 具體內容在std裡
        } else {
                add_action("cantuse","open"); //玩家使用的接口 具體內容在std裡
        }
        //add_action("do_test","test"); //用於巫師測試用 測試ok請註釋此行
}

