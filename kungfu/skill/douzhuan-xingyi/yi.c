// yi.c 斗轉星移
// mud updated on 25th,Feb,2015
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return "斗轉星移"; }
string *limbs = ({"頭部", "頸部", "胸口", "後心","小腹",});
mapping weap =
        (["sword":"劍","blade":"刀","whip":"鞭",
        "club":"棍","staff":"棒","hammer":"錘",
        "throwing":"暗器","dagger":"匕",]);
int perform(object me, object target)
{
        object weapon, weapon2;
        object *obs;
        object der;
                mapping prepare;
        string msg,action,limb, wob, wme,wmsg;
        int ap, dp;
        int damage,wounded,dam,flag;
        int i;
        int delta;
        int zihui, fmsk = me->query_skill("huitong-tianxia", 1);
                string attack_skill, martial_skill;
        int time;
        mapping buff,act;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("「斗轉星移」只能對戰鬥中的對手使用。\n");

        if( userp(me) && !query("yuanshen", me) )
                return notify_fail("你尚未悟道，無法使用"+name()+"。\n");

        if ((int)me->query_skill("douzhuan-xingyi", 1) < 1000)
                return notify_fail("你的斗轉星移不夠嫻熟，不會使用絕招。\n");

        if ((int)me->query_skill("zihui-xinfa", 1) < 1000)
                return notify_fail("你的紫徽心法修為還不到家，難以運用「斗轉星移」。\n");

        if( query("neili", me)<600 )
                return notify_fail("你現在真氣不夠，無法使用「斗轉星移」。\n");

        if (! living(target))
              return notify_fail("對方都已經這樣了，用不著這麼費力吧？\n");

        if( userp(me) )
        {
                if( (time = BUFF_D->get_buff_overtime(me, "dzxy_yi")) > 0 )
                        return notify_fail(MAG"斗轉星移消耗心神太甚，還需等待"+time+"秒。\n"NOR);
        }

        prepare = target->query_skill_prepare();
        if( !prepare ) prepare = ([]);

        weapon = query_temp("weapon", target);
        weapon2 = query_temp("weapon", me);

        if( objectp(weapon) )
                {
                    attack_skill = query("skill_type", weapon);
                        wob = weap[attack_skill];
                        if(objectp(weapon2) && attack_skill != query("skill_type",weapon2))
                        {
                           wme = weap[query("skill_type",weapon2)];
                           wmsg = "$N馭氣於"+weapon2->name()+"，化"+wme+"為"+wob+"。\n";
                           wme = weapon2->name();
                         }
                        if(!objectp(weapon2))
                        wme = HIW+BLINK"無形真氣"NOR;
                }
        else if(  sizeof(prepare) == 0) attack_skill = "unarmed";
        else if(  sizeof(prepare) == 1) attack_skill = (keys(prepare))[0];
        else if(  sizeof(prepare) == 2) attack_skill = (keys(prepare))[query_temp("action_flag", target)];

        if( attack_skill == "pin" )
            attack_skill = "sword";

                martial_skill = target->query_skill_mapped(attack_skill);
        if( !martial_skill )
                martial_skill = attack_skill;

                if( martial_skill == "six-finger"
         ||     martial_skill == "dragon-strike"
         ||     martial_skill == "dagou-bang"
         ||     martial_skill == "sun-finger")
        flag = 1;

                if( SKILL_D(martial_skill)->is_shaolin_skill())
                flag = 2;

                limb = limbs[random(sizeof(limbs))];
        msg = HIG "$N" HIG "施展起絕學「斗轉星移」，以彼之道，還施彼身！\n"NOR;
                msg+= HIG "$N"NOR+HIG"冷笑一聲，彷彿洞徹了$n"NOR+HIG"的成名絕技------"+HIR+to_chinese(martial_skill)+HIG+"!\n";
                msg+= HIG"赫然使出了"+HIR+to_chinese(martial_skill)+HIG+"，好似畢生鑽研一般。\n"NOR;
                if(stringp(wmsg))
                msg+= wmsg;
                act = SKILL_D(martial_skill)->query_action(target,weapon);
                if(act)
                {
                   action = act["action"];
                   msg+= action+"\n";
                   if(wme)
                   msg = replace_string(msg,"$w",wme)+"!\n";
                   msg = replace_string(msg,"$l",limb)+NOR;
                }
        ap = attack_power(me, "force");
        dp = defense_power(target, "parry");

        zihui = me->query_skill("zihui-xinfa", 1);
                zihui+= me->query_skill("shenyuan-gong", 1);
                zihui = zihui / 5000;
                ap = ap + ap /10 * zihui;
        ap = ap + ap /1000 * fmsk;
        if(flag == 1) ap = ap - ap/5;
                if(flag == 2) ap = ap + ap/5;

        delta = ABILITY_D->check_ability(me, "ap_power-dzxy-yi"); // 門派ab
        if( delta ) ap += ap*delta/100;

        der = 0;
        me->start_busy(2);
        addn("neili", -50, me);
                if (ap/2 > dp && query("combat_exp",me) /10 > query("combat_exp",target))
                {
                    msg+= HIK"$n眼見$N使出自己畢生所學，萬念俱灰，坐以待斃。\n"NOR;
                        message_combatd(msg, me, target);
                        target->receive_damage("qi", 100, me);
                        target->die(me);
                }

        else if (ap > dp /10 * 12)
        {
                // Success to make the target attack hiself
            msg += HIK "結果$N" HIK "一招擊出，正好打在$n的"+limb+"上，$n不禁一聲慘叫，摔跌開去。" NOR;
            dam = query("max_qi", target);
            damage = target->receive_damage("qi", dam / 2, me);
            wounded = target->receive_wound("qi", dam / 2, me);
                        message_combatd(msg, me, target);
            message_combatd(COMBAT_D->report_status(target,1), target, me);
                        if( userp(me) )
                tell_object(me, HIW "( 你對" +
                                        query("name", target)+HIW"造成"+
                                        damage + "點傷害，" +
                                        wounded + "點創傷。)\n" NOR);
            if( userp(target) )
                     tell_object(target, HIG "( 你受到" +
                                        query("name", me)+HIG+damage+"點傷害，"+
                                        wounded + "點創傷。)\n" NOR);

        }
                else if (ap / 2 + random(ap) < dp)
        {
                // The enemy has defense
                msg += CYN "然而$p" CYN "內功深厚，並沒有被$P"
                       CYN "這巧妙的勁力所帶動。\n" CYN;
                            message_combatd(msg, me, target);
        }
                else if (sizeof(obs = me->query_enemy() - ({ target })) == 0)
        {
                // No other enemy
                msg += HIC "結果$p" HIC "的招式莫名其妙的變"
                       "了方向，竟然控制不住！幸好身邊沒有別"
                       "人，沒有釀成大禍。\n" NOR;
                            message_combatd(msg, me, target);
        }
                else
        {
                string name;
                // Sucess to make the target attack my enemy

                der = obs[random(sizeof(obs))];
                name = der->name();
                if (name == target->name()) name = "另一個" + name;
                msg += HIG "結果$p" HIG "發出的招式不由自主"
                       "的變了方向，突然攻向" + name + HIG "，不禁令" +
                       name + HIG "大吃一驚，招架不迭！" NOR;
                            message_combatd(msg, me, target);
        }

        if (der)
        {
                // Target attack my enemy
                for (i = 0; i < 2 + random(3); i++)
                {
                        if (! der->is_busy()) der->start_busy(1);
                        COMBAT_D->do_attack(target,der,query_temp("weapon", target),TYPE_LINK);
                }
        }
        time = 38;
        time -= ABILITY_D->check_ability(me, "cd-dzxy-yi"); // ab門派減cd
        time -= ABILITY_D->check_ability(me, "reduce_cd", 2); // talent減cd
        if(wizardp(me) && query("id",me) =="mud") time =2;
        buff = ([
                "caster" : me,
                "target" : me,
                "type"   : "cooldown",
                "type2"  : "dzxy_yi",
                "attr"   : "curse",
                "name"   : "斗轉星移·斗轉星移",
                "time"   : time,
                "buff_msg" : "斗轉星移消耗心神太甚，還需等待"+time+"秒方可再次施展。\n",
                "disa_msg" : "",
                "disa_type": 0,
        ]);

        BUFF_D->buffup(buff);
        return 1;
}
