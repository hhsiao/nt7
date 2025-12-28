#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return HIR"灰飛湮滅"NOR; }

#include "/kungfu/skill/eff_msg.h";
string final(object me, object target, int lvl);

int perform(object me, object target)
{
        string msg;
        int ap, dp, flvl, add_lvl, fmsk;
        int damage, add_dam;
        int is_jifa_beiming;
        int delta,flagremote;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if( objectp(query_temp("weapon", me)) )
                return notify_fail("「灰飛湮滅」只能空手才能施展。\n");

        if (! me->is_fighting(target))
                return notify_fail("「灰飛湮滅」只能對戰鬥中的對手使用。\n");

        if (! target || ! target->is_character())
                return notify_fail("你要對誰施展灰飛湮滅？\n");

        if (! living(target))
                return notify_fail("看清楚，那不是活人。\n");

        if (me->query_skill_prepared("strike") != "liuyang-zhang" )
                return notify_fail("你還沒有將天山六陽掌與逍遙折梅手互備，無法施展。\n");

        if (me->query_skill_prepared("hand") != "zhemei-shou" )
                return notify_fail("你還沒有將天山六陽掌與逍遙折梅手互備，無法施展。\n");

        if (me->query_skill_mapped("dodge") != "lingbo-weibu" )
                return notify_fail("你還沒有激發凌波微步，無法施展。\n");

        if( query("neili", me)< query("max_neili",me)/35 )
                return notify_fail("你的真氣不夠，現在無法施展灰飛湮滅。\n");

        msg = HIY "$N" HIY "左手化掌，右手成刀，不停翻轉向前，掌風到處，一股紫氣席捲而至，將$n" HIY "四周包圍。\n" NOR;

        ap = attack_power(me, "strike") + me->query_skill("hand");
        dp = defense_power(target, "parry") + target->query_skill("unarmed");
        
        delta = ABILITY_D->check_ability(me, "ap_power-lyz-hui"); // 門派ab
        if( delta ) ap += ap*delta/100;
        
        fmsk = me->query_skill("xiaoyao_you",1);
        
        flvl = query("jiali", me);
        add_lvl = flvl * 3;
        add_dam = 100;

        is_jifa_beiming = me->query_skill_mapped("force") == "beiming-shengong" ? 1 : 0;

        if (ap / 2 + random(2*ap) > dp)
        {
                damage = damage_power(me, "strike");
                damage+= query("jiali", me);
                damage+= me->query_all_buff("unarmed_damage");
                damage+= damage / 300 * me->query_str();  
                
                delta = ABILITY_D->check_ability(me, "da_power-lyz-hui"); // 門派ab
                if( delta ) damage += damage*delta/100;
                
                flagremote = UNARMED_ATTACK;
                if( fmsk > 1500 && me->query_skill("beiming-shengong",1) > 7500)
                 flagremote = SPECIAL_ATTACK;
                if( fmsk > 2000 && me->query_skill("beiming-shengong",1) > 15000)
                  flagremote = REMOTE_ATTACK;
                
                // 如激發beiming-shengong 有1/3機會內力迸發
                if (random(3) == 1 && is_jifa_beiming)
                {
                        msg += HIW "剎那間，$N" HIW "只覺體內北冥真氣猶如火山噴發般洶湧而出，周身"
                                   "穴位中融和了無數武學高手不同宗派的內力，頃刻間湧出，遊走至雙掌"
                                    "，泛出熾熱的白光 ……\n" NOR;
                        msg = sort_msg(msg);

                        add_dam = 400;
                }

                // 離開逍遙派後威力減半
                if( !(query("family/family_name", me) ||
                    query("family/family_name", me) != "逍遙派") && (!query("reborn/times", me) || 
                    member_array("逍遙派", query("reborn/fams", me)) == -1) ) 
                {
                        damage /= 2;
                        add_dam /= 2;
                }

                if( random(5) == 1 && query("can_perform/liuyang-zhang/zhong", me) )
                {
                        msg += COMBAT_D->do_damage(me, target, flagremote, damage, add_dam+fmsk/10,
                                                   (: final, me, target, add_lvl :));
                }
                else
                {
                        msg += COMBAT_D->do_damage(me, target, flagremote, damage, add_dam+fmsk/10,
                                                   HIR "只見風沙漫天,忽地一掌正中$n" HIR "胸口，隨即"
                                                   "悶哼一聲，鮮血狂噴而出。\n" NOR);
                }

                addn("neili", -query("max_neili", me)/40, me);
                if (me->query_skill("lingbo-weibu", 1) >= 1500 && random(100) < 15)
                {
                        message_combatd(HIW "$N" HIW "默唸凌波微步口訣，身法忽快，絲毫不受出招的阻礙。\n" NOR, me);
                }
                else
                {
                        me->start_busy(2);
                }
        } else
        {
                msg += CYN "可是$p" CYN "身法突變，左躲右閃，竟避過這招。\n" NOR;
                if (me->query_skill("lingbo-weibu", 1) >= 1500 && random(100) < 15)
                {
                        message_combatd(HIW "$N" HIW "默唸凌波微步口訣，身法忽快，絲毫不受出招的阻礙。\n" NOR, me);
                }
                else
                {
                        me->start_busy(3);
                }
                addn("neili", -2500, me);
        }

        message_combatd(msg, me, target);

        return 1;
}

string final(object me, object target, int lvl)
{
          target->affect_by("ss_poison",
                       ([ "level"    : lvl,
                          "id":query("id", me),
                          "duration" : 120 + random(240)]));

          if( random(5) == 1)set("neili", 0, target);

          if (! target->is_busy()) target->start_busy(2 + random(5));

          return HIR "$n" HIR "只覺得一股寒氣透心而過，猶如利刃穿心，難受之極。\n" NOR;
}

