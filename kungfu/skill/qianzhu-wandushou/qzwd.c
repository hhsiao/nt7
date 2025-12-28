// qianzhu-wandushou.c 千蛛萬毒
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return "千蛛萬毒"; }

int perform(object me, object target)
{
        mapping buff;
        string msg;
        int ap, dp, damage;
        int delta, time;
        int fmsk = me->query_skill("wudu-jing", 1);

        if( !target ) target = offensive_target(me);

        if( !target
        ||        !target->is_character()
        ||        !me->is_fighting(target) )
                return notify_fail("千蛛萬毒只能對戰鬥中的對手使用。\n");

        if( !query("yuanshen_level", me) )
                return notify_fail("你還沒有修煉元神,不能使用這一絕技!\n");

        if((int)me->query_skill("poison",1) < 100)
                return notify_fail("你毒技太低,不能使用這一絕技!\n");

        if((int)me->query_skill("wudu-shengong",1) < 80)
                return notify_fail("你五毒神功的功力不夠不能使用千蛛萬毒!\n");

        if((int)me->query_skill("qianzhu-wandushou",1) < 100)
                return notify_fail("你的千蛛萬毒手修為不夠,還不能使用千蛛萬毒的絕技!\n");

        if( query("max_neili", me)<700 )
                return notify_fail("你內力修為不夠, 不能使用千蛛萬毒! \n");

        if( query("neili", me)<200 )
                return notify_fail("你內力不夠, 不能使用千蛛萬毒! \n");

        if( userp(me) ) 
        {
                if( (time = BUFF_D->get_buff_overtime(me, "qzwds_qzwd")) > 0 )
                        return notify_fail("你剛使用過千蛛萬毒，無法在短時間裡積聚毒力! \n");
        }

        msg = HIR "$N一聲獰笑飛身縱起，凌空一指向$n的眉心點去。\n";
        message_combatd(msg, me, target);

        ap = attack_power(me, "hand");
        dp = defense_power(target, "dodge");
        
        delta = ABILITY_D->check_ability(me, "ap_power-qzwds-qzwd"); // 門派ab
        if( delta ) ap += ap*delta/100;
        
        damage = damage_power(me, "hand") + me->query_skill("poison");
        damage+= query("jiali", me);
        damage*=12;
        
        delta = ABILITY_D->check_ability(me, "da_power-qzwds-qzwd"); // 門派ab
        if( delta ) damage += damage*delta/100;
        
        ap *= 2;
        if( ap / 2 + random(ap) +fmsk > dp )
        {
                msg = HIR"只見一縷黑氣從$N的指尖透出，只一閃就沒入$n的眉心！\n" NOR;
                message_combatd(msg, me, target);
                if(target->query_skill("hunyuan-yiqi",1)>me->query_skill("qianzhu-wandushou",1)*12/10&&random(2)==0)
                {
                        msg += RED"$N忽然覺得指力被一團無形的勁力包裹著，緊接著只聽\n"
                              "$n一聲大喝，$N頓時如一根稻草般被拋向遠處。\n" NOR;

                        msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 300+fmsk/10, 
                                RED"$n只覺得一股如山的勁力順指尖猛攻過來，只覺得全身毒氣狂竄。\n忽然胸口一痛，不由“哇”的一聲吐出一口黑血！\n" NOR);

                        message_combatd(msg, me, target);

                        addn("neili", -100, me);
                        me->start_busy(2);
              }
              else
              {
                        damage += damage / 2; 
                        msg = HIR"$n不由一聲慘嚎摔倒在地，身體已痛苦得蜷縮成一團！\n" NOR;
                        msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 400+fmsk/10, 
                                HIR"$n不由一聲慘嚎摔倒在地，身體已痛苦得蜷縮成一團！\n" NOR);
                        message_combatd(msg, me, target);

                        target->receive_wound( "qi",damage, me);
                        target->apply_condition("snake_poison",
                                (int)target->query_condition("snake_poison") + 50 );
                        target->apply_condition("wugong_poison",
                                (int)target->query_condition("wugong_poison") + 50 );
                        target->apply_condition("zhizhu_poison",
                                (int)target->query_condition("zhizhu_poison") + 50 );
                        target->apply_condition("xiezi_poison",
                                (int)target->query_condition("xiezi_poison") + 50 );
                        target->apply_condition("chanchu_poison",
                                (int)target->query_condition("chanchu_poison") + 50 );
                        addn("neili", -100, me);
                        if( !target->is_busy() )
                                target->start_busy(4);
                }
        }
        else
        {
                msg = HIG "可是$n早有準備，一個懶驢打滾，堪堪躲過了這一招。\n" NOR;
                me->start_busy(4);
                message_combatd(msg, me, target);
                addn("neili", -100, me);
        }

        time  = 40;
        time -= ABILITY_D->check_ability(me, "cd-qzwds-qzwd"); // ab門派減cd
        time -= ABILITY_D->check_ability(me, "reduce_cd", 2); // talent減cd
                
        buff =  
	([
	        "caster" : me,
	        "target" : me,
	        "type"   : "cooldown",
	        "type2"  : "qzwds_qzwd",
	        "attr"   : "curse",
	        "name"   : "千蛛萬毒手·千蛛萬毒",
	        "time"   : time,
	        "buff_msg" : "千蛛萬毒消耗心神太甚，還需等待"+time+"秒方可再次施展。\n",
	        "disa_msg" : "",
	        "disa_type": 0,
	]);
	BUFF_D->buffup(buff);
        return 1;
}
