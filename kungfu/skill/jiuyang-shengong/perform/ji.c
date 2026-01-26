// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;

string name() { return HIW "極境" NOR; }

int perform(object me, object target)
{
        mapping buff;
        object *obs;
        string msg;
        int damage;
        int ap, dp;
        int flag;
        int i;
        int p;
        int delta;
        int time;
        int fmsk = me->query_skill("guangming-jing", 1);

        if( query("yuanshen_level", me) < 1 )
                return notify_fail(name() + "需要修煉成元神後才能使用。\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能對戰鬥中的對手使用。\n");

        if (query_temp("weapon", me) || query_temp("secondary_weapon", me))
                return notify_fail(name() + "只能空手施展。\n");

        if (query("max_neili", me) < 8000)
                return notify_fail("你的內力的修為不夠，現在無法使用" + name() + "。\n");

        if (me->query_skill("jiuyang-shengong", 1) < 250)
                return notify_fail("你的九陽神功還不夠嫻熟，難以施展" + name() + "。\n");

        if (me->query_skill_mapped("unarmed") != "jiuyang-shengong")
                return notify_fail("你現在沒有激發九陽神功為拳腳，難以施展" + name() + "。\n");

        if (me->query_skill_mapped("force") != "jiuyang-shengong")
                return notify_fail("你現在沒有激發九陽神功為內功，難以施展" + name() + "。\n");

        if (me->query_skill_prepared("unarmed") != "jiuyang-shengong")
                return notify_fail("你現在沒有準備使用九陽神功，難以施展" + name() + "。\n");

        if ((int)query("neili", me) < 2000)
                return notify_fail("你的真氣不夠，無法運用" + name() + "。\n");

        if( userp(me) )
        {
                  if( (time = BUFF_D->get_buff_overtime(me, "jysg_ji")) > 0 )
                        return notify_fail(MAG"魔光日無極(極境)消耗心神太甚，還需等待"+time+"秒。\n"NOR);
        }

        msg = HIY "只見$N" HIY "雙目微閉，單手託天。掌心頓時騰起一個無比刺眼的"
              "氣團，正是奧\n義「" NOR + HIW "魔光日無極" NOR + HIY "」。霎時"
              "金光萬道，塵沙四起，空氣熾熱，幾欲沸騰。$N" HIY "\n隨即收攏掌心"
              "，氣團爆裂開來，向四周電射而出，光芒足以和日月爭輝。\n\n" NOR;

        addn("neili", -1000, me);

        ap = attack_power(me, "unarmed");
        ap *= 2;

        delta = ABILITY_D->check_ability(me, "ap_power-jysg-ri"); // 門派ab
        if( delta ) ap += ap*delta/100;

        damage = attack_power(me, "force");
        damage+= query("jiali", me);
        damage+= me->query_all_buff("unarmed_damage");
        damage+= damage / 300 * me->query_str();
        damage+= damage*(fmsk/100)*5/100;

        delta = ABILITY_D->check_ability(me, "da_power-jysg-ri"); // 門派ab
        if( delta ) damage += damage*delta/100;

                if( target->query_family() == "星宿派" || target->query_family() == "逍遙派" )
                        damage *= 3;

                dp = defense_power(target, "force");
                if (ap + random(ap) + fmsk > dp)
                {
                        msg += HIR "$n只覺眼前金光萬道，周圍空氣幾欲沸騰，光芒便如千萬細針一齊扎入身體般。\n" NOR;
                        msg += COMBAT_D->do_damage(me, target, SPECIAL_ATTACK, damage, 300+fmsk/15,
                                        HIR "光芒閃過，$n" HIR "卻是呆立當場，動也不動，七"
                                        "竅流血，神情扭曲，煞是恐怖。\n" NOR);
                }
                else
                {
                        msg += HIY "$N只覺眼前金光萬道，周圍空氣幾欲沸騰，大驚之下連忙急運內功，抵禦開來。\n" NOR;
                }
                message_combatd(msg, me, target);
                time  = 40;
                time -= ABILITY_D->check_ability(me, "cd-jysg-ri"); // ab門派減cd
                time -= ABILITY_D->check_ability(me, "reduce_cd", 2); // talent減cd

                buff = ([
                        "caster" : me,
                        "target" : me,
                        "type"   : "cooldown",
                             "type2"  : "jysg_ji",
                        "attr"   : "curse",
                          "name"   : "九陽神功．極境",
                        "time"   : time,
                         "buff_msg" : "極境消耗心神太甚，還需等待"+time+"秒方可再次施展。\n",
                        "disa_msg" : "",
                        "disa_type": 0,
                ]);

                BUFF_D->buffup(buff);
                me->start_busy(5);
                return 1;

}
