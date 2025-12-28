// This program is a part of NITAN MudLIB 
// redl 2014/3
#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
                set_name(NOR WHT "鋼鏰" NOR, ({ "penny", "gang beng" }));
                set("base_value", 10);
                set("long", NOR + WHT "這是一枚硬幣，可以望天上扔(throwing penny)。\n" NOR);
                set("base_unit", "枚");
                set("base_weight", 100);
                set("unit", "堆");
                set_amount(1);
                set("set_data", 1);
                set("auto_load", 1);
}

int do_exchange(string arg)
{
        object ob, me = this_player();
        string target = query("id", me);
        
        if (!arg || (arg!="penny" && arg!="gang beng")) {
                write(NOR "你要扔什麼東西？\n" NOR);
                return 1;
        }
        
        if(me->is_busy()) return notify_fail("你正忙著呢。\n");

        me->start_busy(2);

        message_vision(NOR CYN "$N" NOR CYN "閉上眼睛掏出一枚$n" NOR CYN "，唸唸有詞地往天上一扔...\n" NOR, me, this_object()); 
        if (random(3)) {
                if (MEMBER_D->is_member(target))
                        MEMBER_D->db_pay_member(target, 1);
                else
                        MEMBER_D->db_create_member(target, 1);
                write(NOR WHT "鋼鏰" NOR HIG "從天上擊落1點泥潭幣，一起跌回了你的衣兜裡。" NOR HIK "(快使用member指令看看吧) \n" NOR); 
                return 1;//不銷燬，返回繼續可扔
        }

        message_vision(NOR CYN "$n" NOR CYN "飄啊飄，飄啊飄...\n就這樣，再也沒有望$N" NOR CYN "一眼地飛走了。\n" NOR, me, this_object()); 
        add_amount(-1); 
        if (query_amount() < 1) 
                destruct(this_object()); 
        return 1;
}


void init()
{
            if (! interactive(this_player()))
                       return;
        add_action("do_exchange", "throwing");
}

