#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
string name() { return HIR "刀劍" + HIY + "九" + HIR "重天" NOR; }
int perform(object me, object target)
{
        mapping buff, data;
        string type1, type2, msg;
        object weapon1, weapon2;
        int ap, dp, damage;
        int fmsk = me->query_skill("daojian-xiaotianwai", 1);
        int da_add;
        int i, count;
        int delta;
        int time;
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }
        if (! me->is_fighting(target))
                return notify_fail(name() + "只能對戰鬥中的對手使用。\n");

        if( me->is_busy() )
                return notify_fail("你正忙著呢。\n");
        if( userp(me) && !query("yuanshen", me) )
                return notify_fail("你尚未悟道，無法使用" + name() + "。\n");

        weapon1 = query_temp("weapon", me);
        weapon2 = query_temp("secondary_weapon", me) || query_temp("handing", me);
        if (! objectp(weapon1) || ! objectp(weapon2))
                return notify_fail("你沒有同時裝備刀劍，難以施展" + name() + "。\n");
        if (query("consistence", weapon2) <= 0)
                return notify_fail("你的" + weapon2->name() + "已經嚴重"
                                   "損壞，無法繼續使用了。\n");
        type1 = query("skill_type", weapon1);
        type2 = query("skill_type", weapon2);
        if ((type1 != "sword" && type1 != "blade")
           || (type2 != "sword" && type2 != "blade"))
                return notify_fail("你所使用的武器不對，難以施展" + name() + "。\n");
        if ((type1 == "sword" && type2 != "blade")
           || (type1 == "blade" && type2 != "sword"))
                return notify_fail("你沒有同時裝備刀劍，難以施展" + name() + "。\n");
        if (me->query_skill_mapped("sword") != "daojian-guizhen"
           || me->query_skill_mapped("blade") != "daojian-guizhen")
                return notify_fail("你沒有激發刀劍歸真，難以施展" + name() + "。\n");
        if (me->query_skill("daojian-guizhen", 1) < 1000)
                return notify_fail("你的劍歸真等級不夠，難以施展" + name() + "。\n");
        if (query("neili", me) < 200000)
                return notify_fail("你現在的真氣不夠，難以施展" + name() + "。\n");
        if (! living(target))
                return notify_fail("對方都已經這樣了，用不著這麼費力吧？\n");

        if( userp(me) )
        {
                if( (time = BUFF_D->get_buff_overtime(me, "djgz_jiu")) > 0 )
                        return notify_fail(MAG"刀劍九重天消耗心神太甚，還需等待"+time+"秒。\n"NOR);
        }

        fmsk = me->query_skill("daojian-xiaotianwai", 1);
        ap = attack_power(me, "blade") + me->query_skill("sword-cognize", 1);
        dp = defense_power(target, "force");

        delta = ABILITY_D->check_ability(me, "ap_power-djgz-jiu"); // 門派ab
        if( delta ) ap += ap*delta/100;
        delta = ABILITY_D->check_ability(me, "ap_power-djgz-tian"); // 門派ab
        if( delta ) ap += ap*delta/100;

        damage = damage_power(me, "blade");
        damage+= damage_power(me, "sword");
        damage+= query("jiali", me);
        damage+= me->query_all_buff("damage");
        damage+= damage / 300 * me->query_str();
        damage = damage / 4;
        delta = ABILITY_D->check_ability(me, "da_power-djgz-jiu"); // 門派ab
        if( delta ) damage += damage*delta/100;
        delta = ABILITY_D->check_ability(me, "da_power-djgz-tian"); // 門派ab
        if( delta ) damage += damage*delta/100;

        msg = HIY "$N" HIY "將" + weapon1->name() + HIY "與" +
              weapon2->name() + HIY "橫置於胸前，運轉出" + name() + HIY "功力，內勁如海嘯般爆發。" NOR;
        msg += HIY "空氣、雲都變成了暗紅色，整個天地靈氣，一草一木上散發出來的生機，包括" HIY "$N" HIY "強大的殺氣、刀魂、劍意，"
                   "在瞬間全部凝聚在了一起，隨著手中" + weapon1->name() + HIY "和" + weapon2->name() + HIY "的共鳴，所有阻擋在"
                   HIY"$N" HIY "面前的東西，好像全部在一瞬間被擊碎，迫開。整個天空，似乎被斬成了兩半，捅出了一個窟窿。"
                   "這一人、一刀、一劍毫不留情的，狠狠的飛向了"HIY "$n"HIY"。\n\n" NOR;
        ap *= 2;

        if (ap / 2 + random(ap) > dp)
        {
                msg += HIR "$n" HIR "哪裡見過$N" HIR "這樣的氣勢，這樣的武功，不禁心"
                       "生懼意，招架頓時散亂，全然不成章理。\n" NOR;
                target->receive_damage("jing", damage / 2);
                target->receive_wound("jing", damage / 3);
                msg += COMBAT_D->do_damage(me, target, SPECIAL_ATTACK, damage, 200,
                                           HIR "$n" HIR "失魂落魄， 一時竟不知抵擋"
                                           "，被$N" HIR "一劍刺中要害，鮮血四濺受"
                                           "傷不輕。\n" NOR);
                ap += ap / 5;
                damage += damage / 3;
        } else
        {
                msg += HIG "$n" HIG "見$N" HIG "殺氣大漲，絲毫不"
                       "敢大意，急忙收斂心神，努力不受干擾。\n" NOR;
        }
        message_combatd(sort_msg(msg), me, target);
        msg = HIW "\n突然間$N" HIW "身形一展，右手" + weapon1->name() +
               HIW "忽地一振，凌空卷出一道半弧，直劈$n" HIW "而去。\n" NOR;
        if (fmsk > 800)
        {
                damage = damage + damage / 3;
                da_add = (80 + fmsk / 15) + (80 + fmsk / 15) / 2;
        }
        if (ap / 2 + random(ap) > dp)
        {
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, da_add,
                                           HIR "$n" HIR "奮力抵擋，卻哪裡招架得住"
                                           "，被$N" HIR "一招劃中要脈，鮮血四處飛"
                                           "濺。\n" NOR);
        } else
        {
                msg += CYN "$n" CYN "心知這一招的凌厲，急忙凝神"
                       "聚氣，小心拆招，絲毫無損。\n" NOR;
        }
        message_combatd(msg, me, target);
        msg = HIW "\n接著$N" HIW "又將左手" + weapon2->name() +
               HIW "朝$n" HIW "平平遞出，招式看似簡單，卻蘊藏著"
               "極大的殺著。\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
                /*
                weapon1->move(me, 1);
                weapon2->wield();
                */
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, da_add,
                                           HIR "$n" HIR "只覺眼花繚亂，全然無法洞"
                                           "察先機，$N" HIR "一招命中，射出一柱鮮"
                                           "血。\n" NOR);
                /*
                weapon2->move(me, 1);
                weapon1->wield();
                set_temp("handing", weapon2, me);
                */
        } else
        {
                msg += CYN "$n" CYN "心知這一招的凌厲，急忙凝神"
                       "聚氣，小心拆招，絲毫無損。\n" NOR;
        }
        message_combatd(msg, me, target);
        if( fmsk >= 1000 && query("neili", me)>1000000 )
        {
                msg = HIC "\n====================" HIY" 刀" HIR "  劍" HIG "  嘯" HIW "  天  外" HIC " ====================" NOR;
                msg += HIC "\n猛然間，$N" HIC "手中" + weapon1->name() + HIC "和" + weapon2->name() + HIC +
                           "發出震天般的長嘯，伴隨著兩道光華飛至天際，但見天雲突變，\n轉眼間，數道金光從天邊劃過，飛向$n" HIC "。\n" NOR;
                if (ap / 2 + random(ap)  + fmsk / 2 > dp)
                {
                        damage *= 3;
                        msg += COMBAT_D->do_damage(me, target, SPECIAL_ATTACK, damage, 350,
                                           HIR "$n" HIR "剎那間目瞪口呆，全然無法相信"
                                           "眼前之景象，$N" HIR "一招命中，射出兩柱鮮"
                                           "血。\n" NOR);
                        addn("neili", -500, me);

                        count = me->query_skill("martial-cognize", 1) + me->query_skill("sword-cognize", 1);
                        count /= 100;
                        if (! target->is_busy())
                                target->start_busy(8 + random(count));

                        target->set_weak(3 + random(count));
                } else
                {
                        msg += CYN "$n" CYN "絲毫不被眼前景象所影響，從容閃躲，避開這一招。\n" NOR;
                }
                message_combatd(msg, me, target);
        }

        count = 0;
        ap = attack_power(me, "blade");
        dp = defense_power(target, "parry");
        if (ap / 2 + random(ap) > dp)
        {
                msg = HIW "$n" HIW "只見無數刀光劍影向自己逼"
                       "來，頓感眼花繚亂，心底寒意油然而生。\n" NOR;
                count = ap / 15;
                set_temp("daojian-guizhen/max_pfm", 1, me);
        } else
        {
                msg = HIG "$n" HIG "突然發現自己四周皆被刀光"
                       "劍影所包圍，心知不妙，急忙小心招架。\n" NOR;
                count = ap / 30;
        }
        message_combatd(msg, me, target);

        addn("neili", -500, me);
        addn_temp("apply/attack", count+fmsk, me);
        addn_temp("apply/damage", count*2/3+fmsk, me);
        addn_temp("apply/avoid_locked", 50, me);
        for (i = 0; i < 12; i++)
        {
                if (! me->is_fighting(target))
                        break;
                COMBAT_D->do_attack(me, target, (random(2) ? weapon1:weapon2), TYPE_LINK);
        }
        addn_temp("apply/attack", -count-fmsk, me);
        addn_temp("apply/damage", -count*2/3-fmsk, me);
        addn_temp("apply/avoid_locked", -50, me);
        delete_temp("daojian-guizhen/max_pfm", me);
        me->start_busy(3 + random(2));

        message_combatd(msg, me, target);
        time  = 40;
        time -= ABILITY_D->check_ability(me, "cd-djgz-jiu"); // ab門派減cd
        time -= ABILITY_D->check_ability(me, "reduce_cd", 2); // talent減cd
        if( wiz_level(me) > 2) time = 2;
        buff = ([
                "caster" : me,
                "target" : me,
                "type"   : "cooldown",
                "type2"  : "djgz_jiu",
                "attr"   : "curse",
                "name"   : "刀劍歸真．刀劍九重天",
                "time"   : time,
                "buff_msg" : "刀劍九重天消耗心神太甚，還需等待"+time+"秒方可再次施展。\n",
                "disa_msg" : "",
                "disa_type": 0,
        ]);

        BUFF_D->buffup(buff);
        return 1;
}
