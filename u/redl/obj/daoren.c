// This program is a part of NITAN MudLIB 
// redl 2013/5/10

#include <ansi.h>
inherit ITEM;

int clean_up() { return 1;}

void create()
{
        set_name(NOR "無名道人" NOR, ({"dao ren"}));
                set("long",  NOR "原來這是具早就坐化的屍骨，手結千鈞血心印，衣襟上繡著朵小紅花。\n" NOR);
                set("weight", 1000000000);
                set("unit", "具");
                set("no_store", "這是對死者的大不敬！\n"); 
                set("no_steal", "這是對死者的大不敬！\n"); 
                set("no_beg", "這是對死者的大不敬！\n"); 
                set("no_get", "這是對死者的大不敬！\n"); 
                set("no_uget", "這是對死者的大不敬！\n"); 
        setup();
}

void init()
{
                object me = this_player();
        if (query("redl/gethomerune", me)<3) add_action("do_action", "");
        delete_temp("has_kneelredl", this_player());
}

int do_action(string arg)
{
        string action = query_verb();
        object me = this_player();
        //tell_object(me, YEL + "id:<" + query("id",me) + "> action:<" + action + ">" + ((arg != "") ? " "+arg : "") + "\n" + NOR); 
        if (action=="look" && arg=="dao ren" && !query_temp("looked")) {
                me->start_busy(3);
                set_temp("looked", 1);
                        me->remove_call_out("do_look");
                        call_out("do_look", 2, me);
                } else if (action=="kneel" && arg=="dao ren") {
                        if(me->is_busy()) {
                                tell_object(me, NOR "你態度過於隨便，怎麼也跪不下去。\n" NOR);
                                me->start_busy(3+ random(2));
                                return 1;
                        }
                        me->start_busy(2);
                        if (!query_temp("has_kneelredl", me)) set_temp("has_kneelredl", 0, me);
                        addn_temp("has_kneelredl", 1, me);
                        message_vision(NOR "$N恭謹地向$n" NOR "磕了"+chinese_number(query_temp("has_kneelredl", me))+"個響頭。\n" NOR, me, this_object());
                        return 1;
                } // else if (arg=="dao ren") {
//                      me->command(action + " " + query("id", me));
//                      me->command(action + " " + query("id", me));
//              }
        return 0;
}

int do_look(object me)
{
        int ki = query_temp("has_kneelredl", me), i;
        delete_temp("has_kneelredl", me);
        
        if (
                !query_temp("can_enterredlroom", me) && 
                query("id", me) != "redl" && query("couple/couple_id", me) != "redl" && 
                (query("get_time", environment())>time() - 5400) 
                ) {
                        message_vision(YEL "在$N的凝目注視下，$n" YEL "的遺骸瞬間塌化成塵，隨風就飄散到九天外去了。\n" NOR, me, this_object());
                        destruct(this_object());
                        return 1;
                }
        
        if (ki > 10) ki = 10;
        
        message_vision(YEL "在$N的凝目注視下，$n" YEL "的遺骸瞬間塌化成塵，隨風就飄散到九天外去了。\n" NOR, me, this_object());

        if (!query_temp("has_getrune", me) && !random(5)) 
                if (ki > 2) {
                set_temp("has_getrune", 1, me);
                i = (11 - ki);
                for(int i2 = i; i2 > 0; i2--) { new("/clone/tessera/rune" + to_string(20 + ki))->move(me);      }
                tell_object(me, HIG "你感覺手心裡多了點東西，連忙定睛一看，原來是" + chinese_number(i) + "個符文(rune" + to_string(20 + ki) + ")。\n" NOR);
                addn("redl/gethomerune", 1, me);
                if (query("redl/gethomerune", me)>2)
                        tell_object(me, YEL "你隱隱約約聽到一個聲音在你腦海裡響起：不要再回來了，不可對人說你是我徒弟。\n" NOR);
        }
        
        if (!random(4)) new(__DIR__"mbox")->move(environment());
        set("get_time", time(), environment());
        destruct(this_object());
        return 1;
}



