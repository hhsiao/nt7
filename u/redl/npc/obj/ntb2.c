// This program is a part of NITAN MudLIB 
// redl 2013/8
#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        int d = (time() - 1392799000) / 864000; //每10天增值1nt
        set_name(NOR BBLU HIW "泥潭週歲股票" NOR, ({ "ntb" }));
        //基礎價值25nt，建議商店出售為50nt(考慮最低七折情況下售價35nt)，一年後等於25+36=61nt
                set("base_value", d+25);
                set("long", NOR + WHT "這是發行在泥潭週歲時的股票，目前可以(exchange)兌換成" + (string)(query("base_value")) + "點泥潭幣。\n" NOR);
                set("base_unit", "張");
                set("base_weight", 3600);
                set("unit", "疊");
        set_amount(1);
                                     set("set_data", 1);
                                     set("auto_load", 1);
}

int do_exchange()
{
        object ob, me = this_player();
        string target = query("id", me);
        int d = query("base_value");
        
        if(me->is_busy()) return notify_fail("你正忙著，沒空兌換泥潭幣。\n");
        me->start_busy(2);

        //30天后才準許兌換
        if (time() < (1392799000 + 86400 * 30)) return notify_fail("這種股票還沒有到兌換期，再等等吧。\n");
        
//        if (! objectp(ob = UPDATE_D->global_find_player(target)))
//            return notify_fail("沒有這個人！\n");

 if (d > 50) d = 50;


        if (MEMBER_D->is_member(target))
                MEMBER_D->db_pay_member(target, d);
        else
                MEMBER_D->db_create_member(target, d);

        log_file("static/yangyong2",sprintf("%s %s 泥潭週歲股->? $NT, 賬戶餘 %d $NT\n",TIME_D->replace_ctime(time()), target, MEMBER_D->db_query_member(me, "money"))); 


        CHANNEL_D->channel_broadcast("chat", ( NOR + HIC + query("name", me) + NOR + HIC + "兌換泥潭週歲股獲得" + chinese_number(d) + NOR + HIC + "點泥潭幣。\n" + NOR )); 
//      write("兌換ok\n");


//         UPDATE_D->global_destruct_player(ob, 1);
        
        add_amount(-1); 
        if (query_amount() < 1) 
                destruct(this_object()); 
        return 1;
}


void init()
{
                if (! interactive(this_player()))
                        return;
        add_action("do_exchange", "exchange");
}


