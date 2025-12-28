
#include <ansi.h>
#include <combat.h>

string name() { return HIM "小樓一夜聽春雨" NOR; }

#include "/kungfu/skill/eff_msg.h"
inherit F_SSERVER;

int perform(object me, object target)
{
        mapping buff;
        object weapon;
        object *obs;
        int damage;
        string msg;
        int ap, dp, md, ly;
        int flag, i, p;
        int fmsk = me->query_skill("motun-tianxia", 1);
        int delta, delta2;
        int time;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能對戰鬥中的對手使用。\n");

        if( !objectp(weapon=query_temp("weapon", me)) ||
            query("skill_type", weapon) != "blade" )
                return notify_fail("你使用的武器不對，難以施展" + name() + "。\n");

        if ((int)me->query_skill("force") < 160)
                return notify_fail("你的內功火候不夠，難以施展" + name() + "。\n");

        if ((int)me->query_skill("moon-blade", 1) < 200)
                return notify_fail("你的圓月彎刀還不到家，難以施展" + name() + "。\n");

        if (me->query_skill_mapped("blade") != "moon-blade")
                return notify_fail("你沒有激發圓月彎刀，難以施展" + name() + "。\n");

        if( query("neili", me)<200 )
                return notify_fail("你的真氣不夠，難以施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("對方都已經這樣了，用不著這麼費力吧？\n");

        msg = HBRED "小樓一夜聽春雨：圓月落，刀光起。縱橫大地十萬裡。刀光寒如雪，何處聽春雨？\n" NOR
              HIY "只聽唰的一聲，" + weapon->name() + HIY "出手了！一切只能以一個快字去形容，發生在肉眼難看清楚的高速下，\n"
              "$N" HIY "這一刀劈出時，好像也是直直的，但是這筆直劈出來的一刀，竟忽然閃起了一道彎彎的刀光。\n"
              "彎彎的刀，彎彎的刀光，開始時宛如一彎新月，忽然間就變成了一道飛虹。這一道彎彎的刀光閃起時，\n"
              + weapon->name() + HIY "上的妖異之氣，使人為之震眩迷惑。\n" NOR;

        ap = attack_power(me, "blade");
        ap += ap * (fmsk/100)* 5 / 100;
        dp = defense_power(target, "dodge");

        md = me->query_skill("moon-blade", 1);
        ly = target->query_skill("lonely-sword", 1);
        
        delta = ABILITY_D->check_ability(me, "ap_power-yywd-ting"); // 門派ab
        if( delta ) ap += ap*delta/100;
        
        if (ap * 2 / 3 + random(ap) > dp )
        {
                damage = 0;
                if (me->query_skill("blade") > target->query_skill("force") &&
                    query("reborn/times", me) >= query("reborn/times", target) && random(md)>ly )
                {
                        addn("neili", -100, me);
                        msg += HIR "當$n" HIR "感到$N" HIR "出手時，" + weapon->name() + HIR "早已揮出，化作滿月時的月光，劃過兩丈的虛空劈向$n。\n"
                               "$n" HIR "只感到周遭所有的氣流和生氣都似被$N" HIR "這驚天動地的一招吸個一絲不剩，一派生機盡絕，\n"
                               "死亡和肅殺的駭人味兒。只聽得輕輕的一聲響，那道彎彎的刀光卻還在，又彎彎地一轉。然後美如月光的刀氣消失了，\n"
                               "所有的聲音都沉寂，所有的動作都停頓。$N" HIR "還是像一瞬前那麼樣靜靜地站在那裡，好像根本沒有動過。可是$N"
                               HIR "手裡的" + weapon->name() + HIR "已經在滴著血。\n" NOR;
                        damage = -1;
                } else
                {
                        addn("neili", -600, me);
                        damage = damage_power(me, "blade");
                        damage+= me->query_all_buff("damage");
                        damage+= query("jiali", me);
                        damage+= damage / 300 * me->query_str();
                        damage+= damage * (fmsk/100)* 5 / 100;
                        damage+= damage/5;
                        
                        delta2 = ABILITY_D->check_ability(me, "da_power-yywd-ting"); // 門派ab
                        if( delta2 ) damage += damage*delta2/100;
        
                        msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 300,
                                                   HIR "結果$p" HIR "閃避不及，只覺得"
                                                   "一股冰寒的刀氣掠過全身，$n全身頓時鮮血淋漓！\n" NOR);
                }
        } else
        {
                
                addn("neili", -300, me);
                msg += CYN "可是$p" CYN "識破了$P"
                       CYN "這一招，斜斜一躍避開。\n" NOR;
        }
        message_combatd(msg, me, target);
        me->start_busy(4);
        if (damage < 0)
                target->die(me);
                        
        if( userp(me) )
        {
                    if( BUFF_D->get_buff_overtime(me, "yywd_ting") > 0 ) 
                    {
                            return 1;
                    }
        }
        if( fmsk >= 1000 && query("neili", me)>1000 && sizeof(obs = me->query_enemy()) )
        {
                msg = HIC "\n====================" HIY" 魔" HIR "  吞" HIG "  天" HIW "  下" HIC " ====================" NOR;
                msg += HIC "\n猛然間，$N" HIC "手中" + weapon->name() + HIC +
                           "發出震天般的長嘯，伴隨著九幽魔氣湧至天際，但見天雲突變，\n轉眼間，幻化出魔頭張開大嘴，吞噬一切。\n" NOR;
                
                
                message_combatd(msg, me, 0, obs);
                for (flag = 0, i = 0; i < sizeof(obs); i++)
                {
                        if( !obs[i] ) continue;
                        dp = defense_power(obs[i], "parry") + obs[i]->query_skill("taoism", 1);
        
                        if (ap / 2 + random(ap)  + fmsk > dp)
                        {
                                damage = damage_power(me, "blade");
                                damage+= me->query_all_buff("damage");
                                damage+= query("jiali", me);
                                damage+= damage / 300 * me->query_str();
                                                                damage*= 3;
                                damage+= damage * (fmsk/100)* 5 / 100;
                                damage+= random(damage);
                                if( delta2 ) damage += damage*delta2/100;
                                if( wiz_level(me) > 2) tell_object(me,"damage = "+damage+"\n");
                                obs[i]->receive_damage("qi", damage, me);
                                obs[i]->receive_wound("qi", damage, me);
                                obs[i]->receive_damage("jing", damage*6, me);
                                obs[i]->receive_wound("jing", damage*3, me);                                                        
                                tell_object(obs[i], HIR "你剎那間目瞪口呆，全然無法相信"
                                           "眼前之景象，頓時被一招命中，射出無數柱鮮"
                                           "血。\n" NOR);
                                addn("neili", -500, me);
                                flag = 1;
                                p=query("qi", obs[i])*100/query("max_qi", obs[i]);
                                switch (random(3))
                                {
                                case 0:
                                msg = HIR "只見" + obs[i]->name() +
                                      HIR "手舞足蹈，忘乎所以，忽"
                                      "然大叫一聲，吐血不止！\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                
                                break;
                                case 1:
                                msg = HIR "卻見" + obs[i]->name() +
                                      HIR "容貌哀慼，似乎想起了什"
                                      "麼傷心之事，身子一晃，嘔出數口鮮血！\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;
                                default:
                                msg = HIR + obs[i]->name() +
                                      HIR "呆立當場，一動不動，有如中"
                                      "邪，七竅都迸出鮮血來。\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;
                                }
                                message("vision", msg, environment(me), ({ obs[i] }));
                                if (! obs[i]->is_busy())
                                        obs[i]->start_busy(3 + random(3));
                        } else
                        {
                                tell_object(obs[i], HIC "你發現眼前的景物似幻似真，連忙"
                                            "默運內功，不受困擾。\n" NOR);
                                addn("neili", -200, obs[i]);
                        }
                        if( query("neili", obs[i])<0 )
                                set("neili", 0, obs[i]);
                }
                
                if( !flag )
                        message_combatd(HIM "然而沒有任何人受了$N"
                               HIM "的影響。\n\n" NOR, me, 0, obs);
        }
        time  = 40;
        time -= ABILITY_D->check_ability(me, "cd-yywd-ting"); // ab門派減cd 
        time -= ABILITY_D->check_ability(me, "reduce_cd", 2); // talent減cd
        if( wiz_level(me) > 2) time = 2;
           buff =
           ([ 
                   "caster" : me,
                   "target" : me,
                   "type"   : "cooldown",
                   "type2"  : "yywd_ting", 
                   "attr"   : "curse",
                   "name"   : "圓月彎刀·聽春雨",
                   "time"   : time,
                   "buff_msg" : "小樓一夜聽春雨消耗心神太甚，還需等待"+time+"秒方可再次施展。\n", 
                   "disa_msg" : "", 
                   "disa_type": 0,
           ]);
           BUFF_D->buffup(buff);
        return 1;
}

