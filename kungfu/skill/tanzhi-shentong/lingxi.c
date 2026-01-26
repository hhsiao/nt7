#include <ansi.h>
#include <combat.h>

string name() { return HIR "靈犀一指" NOR; }

inherit F_SSERVER;

int perform(object me, object target)
{
        mapping buff, data;
        string msg;
        int ap, dp, damage, p;
        int fmsk = me->query_skill("qimen-xuanshu", 1);
        int delta, delta2;
        int time;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(name() + "只能對戰鬥中的對手使用。\n");

        if( userp(me) && !query("yuanshen", me) )
                return notify_fail("你尚未悟道，無法使用" + name() + "。\n");

        if( (int)me->query_skill("tanzhi-shentong", 1) < 100 )
                return notify_fail("你的彈指神通不夠嫻熟，無法使用靈犀一指。\n");

        if( query_temp("weapon", me) )
                return notify_fail("靈犀一指須空手使用。\n");

        if( (int)me->query_skill("tanzhi-shentong", 1) < 1000 )
                return notify_fail("你的彈指神通不夠嫻熟，難以施展" + name() + "。\n");

        if( (int)me->query_skill("qimen-wuxing", 1) < 200 )
                return notify_fail("你的奇門五行修為不夠，難以施展" + name() + "。\n");

        if( me->query_skill_mapped("finger") != "tanzhi-shentong" )
                return notify_fail("你沒有激發彈指神通，難以施展" + name() + "。\n");

        if( me->query_skill_prepared("finger") != "tanzhi-shentong" )
                return notify_fail("你沒有準備彈指神通，難以施展" + name() + "。\n");

        if( query("neili", me) < 3500 )
                return notify_fail("你的內力不足，難以施展" + name() + "。\n");

        if( !living(target) )
                return notify_fail("對方都已經這樣了，用不著這麼費力吧？\n");

        if( userp(me) )
        {
                if( (time = BUFF_D->get_buff_overtime(me, "tzst_lingxi")) > 0 )
                        return notify_fail(MAG"靈犀一指消耗心神太甚，還需等待"+time+"秒。\n"NOR);
        }

        msg = HIR "只見$N" HIR "周身罡氣激盪，渾身上下一片緋紅，像是變成了火焰晶體，整個人燃燒起來。渾身火焰如一條條江河一般，朝著$N"HIR"食指指尖湧去。\n"NOR;
        msg += HIY "一剎那，指尖的火焰光芒耀眼無比，將天上的陽光都完全遮擋了下來，整個天地突然就暗了下來，唯有那一點光芒，奪目刺眼。\n" NOR;
        msg += HIW "那一點光芒在$n"HIW"眼中已化作千道，萬道，空間裂開一道道細縫，而$N"HIW"的身影卻慢慢高大起來，潮聲漸落，那一點光芒久久不見消散。\n";
        target->set_weak(5);
        if( !target->is_busy() ) target->start_busy(2);

        ap = attack_power(me, "finger") + me->query_skill("qimen-wuxing", 1);
        dp = defense_power(target, "dodge") + target->query_skill("qimen-wuxing", 1);

        delta = ABILITY_D->check_ability(me, "ap_power-tzst-lingxi"); // 門派ab
        if( delta ) ap += ap*delta/100;

        damage = damage_power(me, "finger");
        damage+= query("jiali", me);
        damage+= me->query_all_buff("unarmed_damage");
        damage+= damage / 300 * me->query_str();
        damage*= 6;

        delta2 = ABILITY_D->check_ability(me, "da_power-tzst-lingxi"); // 門派ab
        if( delta2 ) damage += damage*delta2/100;

        ap *= 2;
        if( ap / 2 + random(ap) > dp )
        {
                msg += "$n躲閃不及，“噗”地一聲，被指勁擊中前胸！\n";
                msg += COMBAT_D->do_damage(me, target, SPECIAL_ATTACK, damage, 375 + fmsk / 10,
                                                   HIR "你聽到“嗤”的一聲，身上竟然濺到幾滴鮮血！\n" NOR);
        }
        else if( ap / 2 + random(ap) + fmsk > dp )
        {
                msg += "$n向旁邊一閃，讓過了勁風，沒想到這股指勁竟然有回力，從$n背後倒轉回來，正刺中$p的後背。\n";
                msg += COMBAT_D->do_damage(me, target, SPECIAL_ATTACK, damage, 375 + fmsk / 20,
                                                   HIR "你聽到“嗤”的一聲，身上竟然濺到幾滴鮮血！\n" NOR);

        }
        else
        {
                msg += "$n向旁邊一閃，讓過了勁風，卻忽然發覺這股指勁竟然有回力，匆忙中只好一個前撲才堪堪躲過，模樣狼狽之極。\n" NOR;
        }
        message_combatd(msg, me, target);
        me->add("neili", -3000);
        me->start_busy(3);

        time = 40;
        time -= ABILITY_D->check_ability(me, "cd-tzst-lingxi"); // ab門派減cd
        time -= ABILITY_D->check_ability(me, "reduce_cd", 2); // talent減cd
        if( wiz_level(me) > 2) time = 2;
        buff =
        ([
                "caster" : me,
                "target" : me,
                "type"   : "cooldown",
                "type2"  : "tzst_lingxi",
                "attr"   : "curse",
                "name"   : "彈指神通．靈犀一指",
                "time"   : time,
                "buff_msg" : "靈犀一指消耗心神太甚，還需等待"+time+"秒方可再次施展。\n",
                "disa_msg" : "",
                "disa_type": 0,
        ]);
        BUFF_D->buffup(buff);
        return 1;
}
