// This program is a part of NT MudLIB

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return HIW "刀至上-至上刀" NOR; }

int perform(object me)
{
        mapping buff;
        int dt;
        string msg;
        object weapon, target, weapon2;
        mixed res;
        int ap, dp, count;
        int i, damage;
        int time;
        int fmsk = me->query_skill("motun-tianxia", 1);
        int delta;

        /*
        if( query("family/family_name", me) != "魔教" &&
            query("reborn/family_name", me) != "魔教" )
                return notify_fail("你不是魔教弟子，無法使用" + name() + "。\n");
        */

        if( userp(me) && !query("yuanshen", me) )
                return notify_fail("你尚未悟道，無法使用" + name() + "。\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能對戰鬥中的對手使用。\n");

        if( me->is_busy() )
                return notify_fail("你正在忙著呢。\n");

        if( !objectp(weapon=query_temp("weapon", me)) ||
            query("skill_type", weapon) != "blade" )
                return notify_fail("你使用的武器不對，難以施展" + name() + "。\n");

        if ((int)me->query_skill("moon-blade", 1) < 1000)
                return notify_fail("你圓月彎刀火候不夠，難以施展" + name() + "。\n");

        if (me->query_skill_mapped("blade") != "moon-blade")
                return notify_fail("你沒有激發圓月彎刀，難以施展" + name() + "。\n");

        if ((int)me->query_skill("force") < 1200)
                return notify_fail("你的內功修為不夠，難以施展" + name() + "。\n");

        if( query("max_neili", me)<10000 )
                return notify_fail("你的內力修為不夠，難以施展" + name() + "。\n");

        if( query("neili", me)<1000 )
                return notify_fail("你現在的真氣不足，難以施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("對方都已經這樣了，用不著這麼費力吧？\n");

        if( userp(me) )
        {
                if( (dt = BUFF_D->get_buff_overtime(me, "yywd_dao")) > 0 )
                        return notify_fail(MAG"刀至上-至上刀消耗心神太甚，還需等待"+dt+"秒。\n"NOR);
        }

        ap = attack_power(me, "blade");
        ap += ap * (fmsk/100)* 5 / 100;
        dp = defense_power(target, "force");

        delta = ABILITY_D->check_ability(me, "ap_power-yywd-dao"); // 門派ab
        if( delta ) ap += ap*delta/100;

        if( objectp(weapon2=query_temp("weapon", target)) )
        {
                msg = HBYEL "$N" HBYEL "雙手持刀，一躍而起，勁運刀身，劃出一道完美的弧線，一股刀勁"
                      HBYEL "如一輪新月襲向$n。\n" NOR;

                if (ap / 2 + random(ap) > dp)
                {
                        addn("neili", -500, me);
                        msg += HIR "$n" HIR "暗叫不好，連忙舉起手中兵器抵擋，卻不想虎口劇痛，手中" + weapon2->name() +
                               HIR "捏不住，脫手而出。\n" NOR;

                        weapon2->move(environment(me));
                } else
                {
                        addn("neili", -500, me);
                        msg += CYN "$n" CYN "提升十成功力，頭上青筋暴出，緊握手中" + weapon2->name() +
                               CYN "硬是將$N" CYN "的勁氣抵擋化解了。\n" NOR;
                }
                message_combatd(msg, me, target);
        }

        msg = HBBLU "霎時間$N" HBBLU "身法變得飄忽，不知何時已閃至$n的身前，一招" HIY "「刀至上」\n" NOR +
              HBBLU "刀尖由下至上劃出一個形如滿月的氣勁飛向$n，誓要把$n一分兩半" HBBLU "。\n"NOR;


        dp = defense_power(target, "dodge");
        damage = damage_power(me, "blade");

        delta = ABILITY_D->check_ability(me, "da_power-yywd-dao"); // 門派ab
        if( delta ) damage += damage*delta/100;

        if (ap / 2 + random(ap * 2) > dp)
        {
                damage+= query("jiali", me);
                damage+= me->query_all_buff("damage");
                damage+= damage / 300 * me->query_str();
                damage += damage * (fmsk/100)* 5 / 100;
                damage*= 6;
                target->receive_damage("jing", damage / 8);
                target->receive_wound("jing", damage / 10);
                msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 200+fmsk/10,
                                              HIR "$n" HIR "只覺呼吸緊迫，一股勁風撲面"
                                             "而來，根本避無所避，被$N" HIR "的勁氣襲中"
                                             "全身，各大穴道血氣翻騰，血入箭般噴出。\n" NOR);
                target->set_weak(5);
                addn("neili", -400, me);
        } else
        {
                msg += CYN "$n" CYN "眼見$N" CYN "來勢洶湧，絲毫不"
                       "敢小覷，急忙閃在了一旁。\n" NOR;
                addn("neili", -200, me);
        }

        message_combatd(msg, me, target);

        msg = HBMAG "緊跟著$N" HBMAG "躍向空中，另一殺招" HIB "「至上刀」" NOR +
                   HBMAG "手中刀狂舞，一瞬間天空中多出了無數個滿月，一起向$n" HBMAG "飛去。\n" NOR;

        dp = defense_power(target, "parry");

        if (ap / 2 + random(ap * 2) > dp)
        {
                msg += HIR "$n" HIR "面對$N" HIR "這排山倒海般的攻"
                       "勢，完全無法抵擋，招架散亂，連連退後。\n" NOR;
                count = ap / 5;
        } else
        {
                msg += HIC "$n" HIC "心底微微一驚，心知不妙，急忙"
                       "凝聚心神，竭盡所能化解$N" HIC "數道刀勁。\n" NOR;
                count = 0;
        }

        message_combatd(msg, me, target);

        addn_temp("apply/attack", count, me);
        addn_temp("apply/damage", count*2, me);

        for (i = 0; i < 12; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (! target->is_busy())
                        target->start_busy(3);

                COMBAT_D->do_attack(me, target, weapon, TYPE_LINK);
        }
        addn("neili", -500, me);
        addn_temp("apply/attack", -count, me);
        addn_temp("apply/damage", -count*2, me);

        me->start_busy(2 + random(4));

        time = 40;
        time -= ABILITY_D->check_ability(me, "cd-yywd-dao"); // ab門派減cd
        time -= ABILITY_D->check_ability(me, "reduce_cd", 2); // talent減cd
        if( wiz_level(me) > 2) time = 2;
        buff =
        ([
                "caster" : me,
                "target" : me,
                "type"   : "cooldown",
                "type2"  : "yywd_dao",
                "attr"   : "curse",
                "name"   : "圓月彎刀．刀至上-至上刀",
                "time"   : time,
                "buff_msg" : "刀至上-至上刀消耗心神太甚，還需等待"+time+"秒方可再次施展。\n",
                "disa_msg" : "",
                "disa_type": 0,
        ]);
        BUFF_D->buffup(buff);
        return 1;
}
