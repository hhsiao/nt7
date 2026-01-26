
// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

string name() { return HIY "先天罡氣" NOR; }

inherit F_SSERVER;

string attack1(object me, object target, int damage);
string attack2(object me, object target, int damage);
string attack3(object me, object target, int damage);
string *hbmsg = ({
HBMAG "\n$N" HBMAG "大喝一聲，雙手分使兩招，一起攻出。\n" NOR,
HBMAG "\n$N" HBMAG "雙手齊出，分使不同招式，令人眼花繚亂。\n" NOR,
HBMAG "\n$N" HBMAG "左右手分使兩招，毫不停滯，宛如兩人同時攻出。\n" NOR,
HBMAG "\n$N" HBMAG "左手一招，右手一招，兩招來路各異，令人難以低檔！\n" NOR,
});

int perform(object me, object target)
{
        mapping buff, data;
        object weapon;
        int ap, dp, damage;
        string msg, myfam;
        int delta, delta2, time;
        int taoism,fmsk,xiantian,hb;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能對戰鬥中的對手使用。\n");

        if( userp(me) && !query("yuanshen", me) )
                return notify_fail("你尚未悟道，無法使用" + name() + "。\n");

        if( query_temp("weapon", me) || query_temp("secondary_weapon", me) )
                return notify_fail(name() + "只能空手施展。\n");

        if ((int)me->query_skill("xiantian-gong", 1) < 1000)
                return notify_fail("你的先天功修為不夠，難以施展" + name() + "。\n");

        if( query("max_neili", me)<4000 )
                return notify_fail("你的內力修為不足，難以施展" + name() + "。\n");

        if (me->query_skill_mapped("unarmed") != "xiantian-gong")
                return notify_fail("你沒有激發先天功為拳腳，難以施展" + name() + "。\n");

        if (me->query_skill_mapped("force") != "xiantian-gong")
                return notify_fail("你沒有激發先天功為內功，難以施展" + name() + "。\n");

        if (me->query_skill_prepared("unarmed") != "xiantian-gong")
                return notify_fail("你沒有準備使用先天功，難以施展" + name() + "。\n");

        if( query("neili", me)<2000 )
                return notify_fail("你現在的真氣不足，難以施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("對方都已經這樣了，用不著這麼費力吧？\n");

        if( userp(me) )
        {
             if( (time = BUFF_D->get_buff_overtime(me, "xtg_xian")) > 0 )
                 return notify_fail(MAG"先天罡氣消耗心神太甚，還需等待"+time+"秒。\n"NOR);
        }

        msg = HIW "\n$N" HIW "施出先天罡氣，頓時將方圓十里天地之氣吸入體內"
              "，凝聚於雙手手掌處，左手一揮，層層疊疊湧向$n" HIW "！\n" NOR;

        addn_temp("apply/ap_power", 30, me);

        ap=attack_power(me,"unarmed")+me->query_con()*20;
        dp=defense_power(target,"parry")+target->query_dex()*20;

        delta = ABILITY_D->check_ability(me, "ap_power-xtg-xian"); // 門派ab
        if( delta ) ap += ap*delta/100;

        fmsk = me->query_skill("huajia-su",1);
        taoism = me->query_skill("taoism",1)/2000;
        xiantian = me->query_skill("xiantian-gong",1)/1000;
        hb = me->query_skill("zuoyou-hubo",1);

        damage = damage_power(me, "unarmed");
        damage+= damage_power(me, "force");
        damage+= query("jiali", me);
        damage+= me->query_all_buff("unarmed_damage");
        damage+= damage / 300 * me->query_str();
                damage = damage*(taoism+xiantian);
        damage = damage - random(damage/2);

        if(target->query_family()=="古墓派")
        damage = damage - damage/5;

        if(target->query_family()=="歐陽世家")
        damage = damage + damage/5;
        delta2 = ABILITY_D->check_ability(me, "da_power-xtg-xian"); // 門派ab
        if( delta2 ) damage += damage*delta2/100;

        ap *= 2;
        if(target->query_family()=="古墓派")
        ap = ap - ap/5;
        if(target->query_family()=="歐陽世家")
        ap = ap + ap/5;
        if (ap / 2 + random(ap) > dp)
        {
                if( !target->is_busy() )
                        target->start_busy(2);

                msg += COMBAT_D->do_damage(me, target, SPECIAL_ATTACK, damage, 100+fmsk/10,
                                                    (: attack1, me, target, damage :));
        } else
        {
                msg += CYN "$n" CYN "倒吸一口涼氣，飛身一跳，狼狽地躲過這招。\n" NOR;
        }

        message_combatd(msg, me, target);
        msg = HIW "緊接著，$N" HIW "一聲清嘯，右手虛向$n"HIW"蓋下，龐大的天地之氣洶湧般壓向$n" HIW "！\n" NOR;

        ap=attack_power(me,"unarmed")+me->query_con()*20;
        dp=defense_power(target,"dodge")+target->query_dex()*20;

        if( delta ) ap += ap*delta/100;
        if(target->query_family()=="古墓派")
        ap = ap - ap/20;
        if(target->query_family()=="歐陽世家")
        ap = ap + ap/20;
        ap *= 2;
        if (ap / 2 + random(ap) > dp && living(target))
        {
                if( !target->is_busy() )
                        target->start_busy(2);

                msg += COMBAT_D->do_damage(me, target, SPECIAL_ATTACK, damage, 200+fmsk/5,
                                                   (: attack2, me, target, damage :));
                if (random(me->query_skill("zuoyou-hubo",1)) > 500
                && me->query_family()=="全真教"&&random(3)
                && (query("int", me)<25 || query("int", me)>39)
                && (!me->query_skill("count",1) || query("special_skill/capture", me))
                && living(target))
                {
                    msg += hbmsg[random(sizeof(hbmsg))];
                    msg += COMBAT_D->do_damage(me, target, SPECIAL_ATTACK, damage, 200+fmsk/5,
                                                   (: attack3, me, target, damage :));
                }
        } else
        {
                msg += CYN "$n" CYN "倒吸一口涼氣，飛身一跳，狼狽地躲過這招。\n" NOR;
        }

        message_combatd(msg, me, target);
        addn_temp("apply/ap_power", -30, me);

        addn("neili", -1000, me);

        time  = 38;
        time -= ABILITY_D->check_ability(me, "cd-xtg-xian"); // ab門派減cd
        time -= ABILITY_D->check_ability(me, "reduce_cd", 2); // talent減cd
        if(wizardp(me) && query("id",me) =="mud") time =2;
        buff =
        ([
                "caster" : me,
                "target" : me,
                "type"   : "cooldown",
                "type2"  : "xtg_xian",
                "attr"   : "curse",
                "name"   : "先天功．先天罡氣",
                "time"   : time,
                "buff_msg" : "先天罡氣消耗心神太甚，還需等待"+time+"秒方可再次施展。\n",
                "disa_msg" : "",
                "disa_type": 0,
        ]);
        BUFF_D->buffup(buff);

        me->start_busy(2 + random(2));

        return 1;
}

string attack1(object me, object target, int damage)
{
        string msg;

        target->receive_damage("jing", damage,me);
        target->receive_wound("jing", damage / 2,me);

        msg = HIR "結果$N" HIR "這掌正中$n" HIR "胸"
              "口，先天罡氣登時貫腦而入，接連噴出數"
              "口鮮血。\n" NOR;
        set("neili", 0, target);
        msg += WHT "$n" WHT "只感到胸口一痛，全身真氣宛若遊絲，難受無比。\n" NOR;
        return msg;
}

string attack2(object me, object target, int damage)
{
        string msg;
        msg = HIR "結果$N" HIR "這掌正中$n" HIR "胸"
              "口，先天罡氣登時貫體而入，接連噴出數"
              "口鮮血。\n" NOR;
        target->apply_condition("no_exert", 10);
        msg += WHT "$n" WHT "感到氣脈受損，內息紊亂，說不出的痛苦。\n" NOR;
        return msg;
}
string attack3(object me, object target, int damage)
{
        string msg;
        msg = WHT "$n大驚之下，居然忘了躲閃招架，當即呆立在原地。\n"NOR;
        target->start_busy(5+random(4));
        return msg;
}
