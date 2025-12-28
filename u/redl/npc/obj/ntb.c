// This program is a part of NITAN MudLIB 
// redl 2013/8
#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name(YEL"百元泥潭幣"NOR, ({ "ntb" }));
                set("long", NOR + WHT "這是一張百元大鈔，使用(exchange)來兌換成100泥潭幣。\n" NOR);
                set("base_unit", "張");
                set("base_value", 10000000000);
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
        
        if(me->is_busy()) return notify_fail("你正忙著，沒空兌換泥潭幣。\n");
        me->start_busy(2);
        
//        if (! objectp(ob = UPDATE_D->global_find_player(target)))
//            return notify_fail("沒有這個人！\n");

        if (MEMBER_D->is_member(target))
                MEMBER_D->db_pay_member(target, 100);
        else
                MEMBER_D->db_create_member(target, 100);

        log_file("static/yangyong2",sprintf("%s %s 百元泥潭幣->100 $NT, 賬戶餘 %d $NT\n",TIME_D->replace_ctime(time()), target, MEMBER_D->db_query_member(me, "money"))); 

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



