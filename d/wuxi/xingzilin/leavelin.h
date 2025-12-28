// This program is a part of NITAN MudLIB 
// redl 2012/11/1 
#include <ansi.h>

void apply_boss(object me, int btype, int guarder);

int valid_leave(object me, string dir)
{
        int nt, nk, ng, kar;
        
        if (!query_temp("xzz/kar", me)) set_temp("xzz/kar", 15 + random(19), me); //防止意外出現在林子裡的玩家出現異常
        ng = query("ngroup", environment(me));
        kar = 100 + query_temp("xzz/kar", me);

        if (ng == 1) //外圍
        {
                addn_temp("xzz/ntrip", 10, me);//移動懲罰增加
                addn_temp("xzz/nkill", -2, me);
                nt = query_temp("xzz/ntrip", me);
                nk = query_temp("xzz/nkill", me);
        }
        else if (ng == 2) //深處
        {
                addn_temp("xzz/ntrip2", 10, me);//移動懲罰增加
                addn_temp("xzz/nkill2", -1, me);
                nt = query_temp("xzz/ntrip2", me);
                nk = query_temp("xzz/nkill2", me);
        }
        
        //tell_object(me, HIC" [" + ng + ", kar:"+ kar +"] 測試 - > nt:" + nt + " nk:" + nk + "\n"NOR);  //測試
        
        if (ng && playerp(me) && nt>=to_int(400 * kar / 100)) 
        {
                if (ng == 1) //外圍
                {
                        if (nk < to_int(960 * kar / 100))
                        {
                if (random(5) == 0)
                {
                        me->start_busy(6+random(5));
                        return notify_fail(CYN"突聞一絲異香飄過，你心中警覺頓生，伸手捂住鼻子，腳步也停了下來。\n"NOR);
                }
            }
            else//boss努爾海
            {
                apply_boss(me, ng, 6 + random(3));
                                return notify_fail(CYN"努爾海衝著你一指，你被幾個武士擋住了去路。\n"NOR);
            }
                }
                else if (ng == 2) //深處
                {
                        if (nk < to_int(770 * kar / 100))
                        {
                                if (!query_temp("xzz/poison", me)) //新中毒
                                {
                                        set_temp("xzz/poison", 10, me);
                                        message_vision(HIY"$N突然劇烈咳嗽起來，緊閉的雙眼淚水不絕湧出。\n"NOR, me);
                                        call_out("update_beisu", 6, me);
                                        me->start_busy(5);
                                        return notify_fail(NOR "你中的「" + HIG + "悲酥清風" + NOR + "」毒發，手痠足軟！\n" NOR);
                                }
                                else if (query_temp("xzz/poison", me)<=1000)
                                {
                                        addn_temp("xzz/poison", 5, me);
                                }
                        }
                        else//boss赫連鐵樹
                        {
                apply_boss(me, ng, 2 + random(2));
                                return notify_fail(CYN"赫連鐵樹衝著你一指，你被幾個武士擋住了去路。\n"NOR);
                        }
                }
        }
        
        return ::valid_leave(me, dir);
}


void update_beisu(object me)
{
        int nrnd = random(100);
        
        if( !me ) return;
        if (!query_temp("xzz/poison", me)) return;
        if (query_temp("xzz/poison", me)<=0)
        {
                delete_temp("xzz/poison", me);
                return;
        }
        addn_temp("xzz/poison", -1, me);
        
        if (nrnd < 25)
        {
                tell_object(me, NOR "你中的「" + HIG + "悲酥清風" + NOR + "」毒發，目不能視！\n" NOR );
                set_temp("block_msg/all", 1, me);
                call_out("cimu_end", 3+random(3), me);
        }
        else if (nrnd <75)
        {
                tell_object(me, NOR "你中的「" + HIG + "悲酥清風" + NOR + "」毒發，手痠足軟！\n" NOR );
                me->start_busy(4+random(3));
        }
        else
        {
                me->apply_condition("no_exert", 3+random(4)); 
        }
        me->apply_condition("no_perform", 3+random(4)); 
        
        call_out("update_beisu", 6, me);
}


void cimu_end(object target)
{
        if( target && query_temp("block_msg/all", target) )
        {
                if (living(target)) tell_object(target, HIR "你勉強睜開淚眼，看得見一些景象了。\n" NOR);
                delete_temp("block_msg/all", target);
        }
        return;
}

void apply_boss(object me, int btype, int guarder)
{
        object ob, where;

        me->start_busy(3);
        where = this_object(); //environment(me);
        message_vision(YEL "一陣鐵蹄疾踏聲中，樹林裡突然衝出來" + chinese_number(guarder+1) + "騎人馬將$N團團圍住...\n" NOR, me);
        if (btype == 1)
        {
                while (guarder--) {
                        ob = new(__DIR__"npc/wushi9");
                        ob->move(where); 
                        ob->set_leader(me);
                }
                set_temp("xzz/ntrip", 0, me);
                set_temp("xzz/nkill", 0, me);
                ob = new(__DIR__"npc/bossnu");
        }
        else
        {
                while (guarder--) {
                        ob = new(__DIR__"npc/wushi2345");
                        ob->move(where); 
                        ob->set_leader(me);
                }
                set_temp("xzz/ntrip2", 0, me);
                set_temp("xzz/nkill2", 0, me);
                ob = new(__DIR__"npc/bosshe");
        }
        ob->move(where); 
        ob->set_leader(me);
}




