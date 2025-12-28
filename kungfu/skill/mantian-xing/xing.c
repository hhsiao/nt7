#include <ansi.h>
#include <combat.h>

#define XING "「" HIR "穹外飛星" NOR "」"

#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;

int perform(object me, object target)
{
        mapping buff, data;
        int skill, i, p, n;
        mixed my_exp, ob_exp;
        string pmsg;
        string msg;
        object weapon;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(XING "只能在戰鬥中對對手使用。\n");

        if( !objectp(weapon=query_temp("handing", me)) || 
            query("skill_type", weapon) != "throwing" )
                return notify_fail("你現在手中沒有拿著暗器，難以施展" XING "。\n");

        if (weapon->query_amount() < 15)
                return notify_fail("至少要有十五枚暗器才能施展" XING "。\n");

        if ((skill = me->query_skill("mantian-xing", 1)) < 80)
                return notify_fail("你的滿天星不夠嫻熟，難以施展" XING "。\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("你的內功修為不足，難以施展" XING "。\n");

        if( query("max_neili", me)<1200 )
                return notify_fail("你的內力修為不足，難以施展" XING "。\n");

        if( query("neili", me)<150 )
                return notify_fail("你現在真氣不足，難以施展" XING "。\n");

        if( BUFF_D->check_buff(target, "mtx_xing") ) 
                return notify_fail("對方已經中了你的絕招，現在是廢人一個，趕快進攻吧！\n");

        if (! living(target))
                return notify_fail("對方都已經這樣了，用不著這麼費力吧？\n");

        addn("neili", -100, me);
        weapon->add_amount(-15);

        msg = HIR "$N" HIR "驀地飛身躍起，十指箕張，施出「穹外飛星」將"
              "手中" + weapon->name() + HIR "盡數凌空射出。\n霎時破空聲"
              "驟響，" + weapon->name() + HIR "便如同隕星飛墜一般，籠罩"
              "$n" HIR "各處大穴！\n" NOR;

        my_exp=attack_power(me, "throwing");
        ob_exp=defense_power(target, "dodge");

        //me->want_kill(target);
        if (my_exp / 2 + random(my_exp * 3 / 2) > ob_exp)
        {
                if (target->query_skill("parry") < me->query_skill("throwing"))
                {
                        n = 2 + random(2);
                        if (random(my_exp) > ob_exp) n += 1 + random(2);
                        if (random(my_exp / 2) > ob_exp) n += 1 + random(2);
                        if (random(my_exp / 4) > ob_exp) n += 1 + random(2);

                        msg += HIR "結果$n" HIR "一聲慘叫，同時中了$P" HIR +
                               chinese_number(n)+query("base_unit", weapon)+
                               weapon->name() + HIR "，直感兩耳轟鳴，目不視"
                               "物。\n" NOR;

                        while (n--)
                        {
                                COMBAT_D->clear_ahinfo();
                                weapon->hit_ob(me, target,
                                               query("jiali", me)+100+n*10);
                        }

                        set_temp("feixing", 1, target);
                        data = ([
                                "attack": -skill/4, 
                                "defense": -skill/4, 
                        ]);
                        buff = ([
                                "caster": me,
                                "target": target,
                                "type"  : "mtx_xing",
                                "attr"  : "curse",
                                "name"  : "滿天星·穹外飛星",
                                "time"  : skill/15,
                                "buff_data": data,      
                                "buff_msg" : "",
                                "disa_msg" : HIY "漸漸的你覺得力氣一絲絲的恢復了。\n" NOR,
                        
                        ]);
                        BUFF_D->buffup(buff);
                        
                        target->receive_damage("qi", skill, me);
                        target->receive_wound("qi", skill/2, me);

                        p=query("qi", target)*100/query("max_qi", target);

                        if (stringp(pmsg = COMBAT_D->query_ahinfo()))
                                msg += pmsg;

                        msg += "( $n" + eff_status_msg(p) + " )\n";
                        message_combatd(msg, me, target);

                        tell_object(target, RED "你現在要穴受到重損，乃至全身"
                                            "乏力，提不上半點力道！\n" NOR);
                        tell_object(me, HIC "你心知剛才這招已打中對方要寒，不"
                                            "禁暗自冷笑。\n" NOR);
                } else
                {
                        msg += HIR "$n" HIR "集中生智，雙手畫圈迴旋揮舞，撥弄"
                               "開了要害處的殺著，可還是受了點輕傷。\n" NOR;

                        target->receive_damage("qi", skill);
                        target->receive_wound("qi", skill/2);

                        p=query("qi", target)*100/query("max_qi", target);
                        msg += "( $n" + eff_status_msg(p) + " )\n";
                        message_combatd(msg, me, target);

                        tell_object(target, RED "你只覺全身幾處一陣刺痛，知道"
                                            "自己雖被擊中，但卻是避開了要穴。"
                                            "\n" NOR);
                        //target->kill_ob(me);
                        me->start_busy(1 + random(2));
                }
        } else
        {
                 msg += CYN "可是$n" CYN "小巧騰挪，好不容易避開了"
                        CYN "$N" CYN "鋪天蓋地的攻擊。\n" NOR;
                 me->start_busy(3);
                 message_combatd(msg, me, target);
        }
        return 1;
}
