// This program is a part of NITAN MudLIB 
// redl 2015/10
#include <ansi.h>
inherit ITEM;

void create() 
{ 
              set_name(NOR HIY "金船" HIW"寶箱"NOR, ({"box"}) ); 
                        set_weight(100000000000);
                set("long", NOR "這是金船裡遺落的寶箱，打開(open)試試？\n" NOR);
                set("unit", "個");
                set("value", 1);
                set("no_uget", 1);
                set("no_drop", 1);
                set("no_give", 1);
                set("no_sell", 1);
                set("no_get", 1);
                set("no_steal", 1);
                set("no_beg", 1);
                set("no_put", 1);
                set("no_store", 1);
                set("unique", 1);
                set("no_pawn", 1);
              setup(); 
} 


int do_touch()
{
        object trap;
        object me = this_object();
        object who = this_player();
        
        if (who->is_busy())
        {
                tell_object(who, NOR BUSY_MESSAGE NOR); 
                return 1;
        }
        else if (random(3))
                who->start_busy(1);     
                
        if (query("neili", who)<1000000) {
                tell_object(who, NOR "你內力不足。\n" NOR); 
                return 1;
        }
        if (query("jingli", who)<500000) {
                tell_object(who, NOR "你精力不足。\n" NOR); 
                return 1;
        }
        
        message_vision(NOR CYN "$N運轉真氣到手上，用力去掀箱子的頂蓋。\n" NOR, who); 
        addn("neili", -100000, who);
        addn("jingli", -50000, who);
        addn("touch_num", 1, me);
        if (query("touch_num", me) < 10 || 
                query("touch_num", me) < random(500)) {
                        tell_object(who, NOR "箱子抖了一下，似乎還要繼續加把勁。\n" NOR); 
                        return 1;
                }
        
        tell_object(who, HIW "箱子嘭地炸開，其內元磁真氣四散逃逸(xi)，一點黑星掙脫了漩渦飛進你的手裡，你趕緊張嘴往喉嚨裡一倒。\n" NOR);
        addn("yuan_ci_num", random(6)+ 3, environment(me));
        CHANNEL_D->channel_broadcast("news", HIG "聽說" + HIC + query("name", who) + HIG + "在金船裡得到了一顆" HIY "廣成鐵丹"HIG"。");
        set_temp("jinchuan/iyca", 1, who);
        "/u/redl/teleport/ailao"->yuanci_attack(who);
        set_temp("jinchuan/iyca", 1, who);
        GIFT_D->delay_bonus(who, ([ "exp" : 7500000, "pot" : 2500000, "mar" : 1000000, "prompt" : "你在吞下廣成鐵丹之後"]));
        //destruct(me);
        delete("touch_num", me);//重置
        me->move(get_object("/u/redl/teleport/yuanjiang/chuan" + (string)random(50)));
        trap = new(__DIR__"trap");
        trap->move(get_object("/u/redl/teleport/yuanjiang/chuan" + (string)random(50)));
        trap = new(__DIR__"trap");
        trap->move(get_object("/u/redl/teleport/yuanjiang/chuan" + (string)random(50)));
        trap = new(__DIR__"trap");
        trap->move(get_object("/u/redl/teleport/yuanjiang/chuan" + (string)random(50)));
        return 1;
}

void init()
{
        object me = this_player();
        if (!playerp(me)) return;
        add_action("do_touch", "open"); 
}


