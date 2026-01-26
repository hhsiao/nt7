
// This program is a part of NITAN MudLIB
// hun.c 劍魂

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return HIM "劍魂" NOR; }

int can_not_hubo() { return 1;}

private int remove_attack(object me, object weapon);

int perform(object me, object target)
{
        string *limbs, limb;
        string msg;
        object *ob, weapon;
        mapping buff;
        int ap, dp, count, p;
        int skill;
        int i, damage;
        int time;
        int delta;
        int fmsk = me->query_skill("jianyi", 1);

        if( userp(me) && !query("yuanshen", me) )
                return notify_fail("你尚未悟道，無法施展" + name() + "。\n");

        /*
        if( query("family/family_name", me) != "華山派"
         && member_array("華山派", query("reborn/fams", me)) == -1 )
                return notify_fail("你尚未轉世重生，無法施展" + name() + "。\n");

        if( query("family/family_name", me) != "華山派" )
                return notify_fail("你不是華山派弟子，無法施展" + name() + "。\n");
        */
        /*
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(HUN "只能對戰鬥中的對手使用。\n");
        */

        if( !me->is_fighting() )
                return notify_fail(name() + "只能對戰鬥中的對手使用。\n");

        if( query_temp("dugu_jianhun", me) || BUFF_D->check_buff(me, "protect") )
                return notify_fail("你已在使用" + name() + "了！\n");

        weapon=query_temp("weapon", me);
        if( !objectp(weapon) || query("skill_type", weapon) != "sword" )
                return notify_fail("你手中無劍，如何能夠施展" + name() + "？\n");

        if( (int)me->query_skill("lonely-sword", 1) < 1000 )
                return notify_fail("你的獨孤九劍不夠嫻熟，難以施展" + name() + "。\n");

        if( me->query_skill("force") < 1200 )
                return notify_fail("你的內功火候未到，無法配合杖法施展" + name() + "！\n");

        if( me->query_skill("sword", 1) < 1000 )
                return notify_fail("你劍法修為不足，還不會使用" + name() + "！\n");

        if( me->query_skill("sword-cognize", 1) < 500 )
                return notify_fail("你劍道修養火候未到，還不會使用" + name() + "！\n");

        if( me->query_skill("martial-cognize", 1) < 500 )
                return notify_fail("你武學修養火候未到，還不會使用" + name() + "！\n");

        if( query("neili", me) <= 1000 )
                return notify_fail("你的內力不夠施展" + name() + "！\n");

        if( query("jingli", me) <= 500 )
                return notify_fail("你的精力不夠施展" + name() + "！\n");

        if( userp(me) )
        {
                if( (time = BUFF_D->get_buff_overtime(me, "dgjj_hun")) > 0 )
                        return notify_fail(MAG"劍魂消耗心神太甚，還需等待"+time+"秒。\n"NOR);
        }

        count = me->query_skill("sword-cognize", 1) + me->query_skill("martial-cognize", 1);
        count /= 500;

        msg = HIW "$N" HIW "神態寫意，溫柔撫弄手中的" + weapon->name() + HIW "，只見" + weapon->name() +
              HIW "表面掠過一絲光影，微微顫動，整把劍竟靈動起來、有若生物。\n" NOR
              HIM"$N"HIM"將手中"+query("name", weapon)+HIM"緩緩刺出，劍招隨意無章！\n"NOR
              HIM "這招看似緩慢，其實疾如閃電，看似隨意無章，卻是和" + weapon->name() + HIM "融為一體，無懈可擊，蘊涵著返璞歸真的意境。\n" NOR;

        message_combatd(msg, me);

        damage = damage_power(me, "sword");
        damage += me->query_all_buff("damage");
        damage += query("jiali", me);
        damage += damage / 300 * me->query_str();
        damage *= 9;
        delta = ABILITY_D->check_ability(me, "da_power-dgjj-hun"); // 門派ab
        if( delta ) damage += damage*delta/100;

        ap = attack_power(me, "sword") +
             me->query_skill("dodge");

        ap = ap + ap * fmsk / 1000;

        delta = ABILITY_D->check_ability(me, "ap_power-dgjj-hun"); // 門派ab
        if( delta ) ap += ap*delta/100;

        ob = me->query_enemy();
        skill = me->query_skill("lonely-sword", 1);

        for (i = 0; i < sizeof(ob); i++)
        {
                dp = defense_power(ob[i], "parry") +
                     ob[i]->query_skill("dodge");

                if (ap * 2 / 3 + random(ap) > dp)
                {
                        ob[i]->receive_damage("qi", damage, me);
                        ob[i]->receive_wound("qi", damage / 2, me);
                        ob[i]->set_weak(5);
                        set("neili", 0, ob[i]);
                        set("jiali", 0, ob[i]);
                        ob[i]->apply_condition("no_exert", 3);
                        ob[i]->apply_condition("no_perform", 3);

                        msg = HIR "$n" HIR "想招架卻感無從招架，想躲避也感到無處可躲，登時被$N" HIR "一劍劃過，\n"
                              HIR "遭受重創，一陣錐心的刺痛，全身真氣源源而瀉！\n" NOR;

                        if( delta = ABILITY_D->check_ability(me, "fatal_blow-dgjj-hun") ) // 門派ab
                        {
                                if( random(10) < delta )
                                {
                                        ob[i]->receive_damage("qi", damage*10, me);
                                        ob[i]->receive_wound("qi", damage*10, me);
                                        msg += HIR "緊接著，$N" HIR "追加了致命一擊，給$n" HIR "造成更嚴重的創傷。\n" NOR;
                                }
                        }
                        p=query("qi", ob[i])*100/query("max_qi", ob[i]);
                        msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
                        message_vision(msg, me, ob[i]);
                } else
                {
                        ob[i]->start_busy(2);
                        msg = HIC "$n" HIC "情急之下，不及考慮，倒地一滾，僥倖避開$N" HIC "這一招的攻擊，冷汗直淋！\n" NOR;
                        message_vision(msg, me, ob[i]);
                }
        }

        set_temp("dugu_jianhun", 1, me);
        addn("neili", -200, me);
        addn("jingli", -100, me);

        msg = HIY "$N" HIY "握緊" + weapon->name() + HIY "向天一指, 叫道 : 劍魂一出 ～ 血光漫天 ～ \n"
              HIY "頓時" + weapon->name() + HIY "劍身化出一道紅色的劍形，在天空中恣意飛旋穿梭 ...\n" NOR;

        message_combatd(msg, me);

                if( !objectp(weapon) ) return 1;
                if( query_temp("dugu_jianhun", me) >= count
                ||      !me->is_fighting() )
                {
                                call_out("remove_attack", 0, me, weapon);
                                return 1;
                }

                addn_temp("dugu_jianhun", 1, me);
                message_combatd(HIR "\n劍魂以閃電般的高速在空中穿梭, 以狂亂無比的熱情盡情狂舞 ...\n" NOR, me);

                ob = me->query_enemy();
                if( sizeof(ob) < 2 )
                {
                                addn_temp("str", 2000, me);
                                addn_temp("apply/damage", fmsk*20, me);
                                COMBAT_D->do_attack(me, ob[0], weapon, TYPE_LINK);
                                addn_temp("str", -2000, me);
                                addn_temp("apply/damage", -fmsk*20, me);

                }

                ap = me->query_skill("sword", 1) + me->query_skill("sword-cognize", 1) +
                         me->query_skill("martial-cognize", 1);
                damage=ap+weapon->apply_damage();
                damage += damage_power(me, "sword");
                damage *= 30;

                for (i = 0; i < sizeof(ob); i++)
                {
                                if (! objectp(ob[i])) continue;
                                dp=query("parry", ob[i])+
                                                ob[i]->query_skill("dodge", 1);

                                if (dp / 3 + random(dp) < ap)
                                {
                                                limbs=query("limbs", ob[i]);
                                                if (! arrayp(limbs))
                                                {
                                                                limbs = ({ "身體" });
                                                                set("limbs", limbs, ob[i]);
                                                }
                                                limb = limbs[random(sizeof(limbs))];
                                                ob[i]->start_busy(1);
                                                ob[i]->receive_damage("qi", damage, me);
                                                ob[i]->receive_wound("qi", damage / 2, me);
                                                p=query("qi", ob[i])*100/query("max_qi", ob[i]);
                                                msg = COMBAT_D->damage_msg(damage, "割傷");
                                                msg = replace_string(msg, "$l", limb);
                                                msg = replace_string(msg, "$w", weapon->name());
                                                msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
                                                message_combatd(msg, me, ob[i]);
                                }
                }
//        }
        call_out("remove_attack", 0, me, weapon);

        time  = 40;
        time -= ABILITY_D->check_ability(me, "cd-dgjj-hun"); // ab門派減cd
        time -= ABILITY_D->check_ability(me, "reduce_cd", 2); // talent減cd
        if(wizardp(me) && query("id",me) == "mud") time = 2;
        buff = ([
                "caster" : me,
                "target" : me,
                "type"   : "cooldown",
                "type2"  : "dgjj_hun",
                "attr"   : "curse",
                "name"   : "獨孤九劍．劍魂",
                "time"   : time,
                "buff_msg" : "劍魂消耗心神太甚，還需等待"+time+"秒方可再次施展。\n",
                "disa_msg" : "",
                "disa_type": 0,
        ]);

        BUFF_D->buffup(buff);
        me->start_busy(2);

        return 1;
}

int remove_attack(object me, object weapon)
{
        if( !objectp( me ) ) return 1;
        if( !query_temp("dugu_jianhun", me))return 1;

        delete_temp("dugu_jianhun", me);
        if( !weapon ) return 1;
        message_combatd(HIW "一陣狂舞之後, 劍魂又自動飛入你的手中" + weapon->name() + HIW " ...\n" NOR, me);

        return 1;

}
