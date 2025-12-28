#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return HIY "佛光普照" NOR; }

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage, flagremote = 0;
        int lvl_jingxin = me->query_skill("jingxin", 1);
        int lvl_emjy = me->query_skill("emei-jiuyang", 1);//不須要求mapped
        int lvl_ngxy = me->query_skill("force-cognize", 1);
        int time;
        mapping buff;
        int flagclaw = 0;
        object *obs, newtarget;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能在戰鬥中對對手使用。\n");

        if( query_temp("weapon", me) ||
            query_temp("secondary_weapon", me) )
                return notify_fail("你必須空手才能施展" + name() + "。\n");

        if (me->query_skill("force") < 300)
                return notify_fail("你的內功的修為不夠，無法施展" + name() + "。\n");

        if (me->query_skill("piaoxue-zhang", 1) < 180)
                return notify_fail("你的飄雪穿雲掌修為不夠，無法施展" + name() + "。\n");

        if( query("neili", me)<1000 || query("max_neili", me)<3500 )
                return notify_fail("你的真氣不夠，無法施展" + name() + "。\n");

        if (me->query_skill_mapped("strike") != "piaoxue-zhang")
                return notify_fail("你沒有激發飄雪穿雲掌，無法施展" + name() + "。\n");

        if (me->query_skill_prepared("strike") != "piaoxue-zhang")
                return notify_fail("你沒有準備飄雪穿雲掌，無法施展" + name() + "。\n");

        if (! living(target))
               return notify_fail("對方都已經這樣了，用不著這麼費力吧？\n");

//        if( userp(me) ) 
//        {
                if( (time = BUFF_D->get_buff_overtime(me, "emaq_piaoxuezhao")) > 0 )
                        return notify_fail(MAG"佛光普照消耗心神太甚，還需等待"+time+"秒。\n"NOR);
//        }

        msg = HIY "$N" HIY "運起全身功力，頓時真氣迸發，全身骨骼噼啪作"
              "響，猛然一掌向$n" HIY "\n全力拍出，力求一擊斃敵，正是一"
              "招「佛光普照」。\n" NOR;

        ap = attack_power(me, "strike") +
                                me->query_skill("force") +
                                me->query_skill("martial-cognize") +
                                me->query_skill("force-cognize") +
                                me->query_skill("mahayana") * 3 + 
                                me->query_str()*(100+query("level",me));
        dp = defense_power(target, "dodge") +
                                target->query_skill("force") +
                                target->query_skill("martial-cognize") +
                                target->query_skill("force-cognize") +
                                me->query_con()*100;
        ap = ap + ap * lvl_jingxin / 600;
        ap += ap*(ABILITY_D->check_ability(me, "ap_power-pxz-zhao"))/100; 
        if (target->is_busy()) ap += ap / 6;
        if (BUFF_D->check_buff(me, "ljz_zhixin")) ap += ap / 8;
        
        if( (userp(me) && !query("yuanshen", me)) && 
                (target->query_skill_mapped("force") == "jiuyang-shengong") ) 
                {
                addn("neili", -1000, me);
                me->start_busy(5);
                msg += HIW "只聽轟然一聲巨響，$n" HIW "已被一招正中，可$N"
                       HIW "只覺全身內力猶如江河入\n海，又如水乳交融，登"
                       "時消失得無影無蹤。\n" NOR;
                }
        else 
        if ((target->query_skill_mapped("force") == "jiuyang-shengong") && random(5)<2)//元神後40%
        {
                addn("neili", -1000, me);
                me->start_busy(5);
                msg += HIW "只聽轟然一聲巨響，$n" HIW "已被一招正中，可$N"
                       HIW "只覺全身內力猶如江河入\n海，又如水乳交融，登"
                       "時消失得無影無蹤。\n" NOR;
        } 
        else
        if (ap * 4 / 5 + random(ap) > dp)
        {
                        damage = damage_power(me, "strike");// + me->query_skill("mahayana", 1);
                        if (BUFF_D->check_buff(me, "ljz_zhixin") && BUFF_D->check_buff(me, "ljz_fengyun") && BUFF_D->check_buff(me, "ljz-niepan")) 
                                damage += me->query_all_buff("damage");
                        damage += damage * query("jiali", me) / 5000; 
                        damage += damage * lvl_jingxin / 150;
                 if(!userp(me) && userp(target)) {
                       damage = damage / query("level", target);
                 }
                        addn("neili", -1000, me);
                
                        if (!target->is_busy())
                                target->start_busy(1);
                       
                        time = 4;
                        if( BUFF_D->check_buff(me, "ljz_fengyun") ) time -= 1;
                        if ( BUFF_D->check_buff(me, "ljz-niepan") ) time -= 1;
                        me->start_busy(1 + random(time));
                        
                        if (lvl_emjy > 200 && (!userp(me) || query("yuanshen", me))) //by redl 元神大招效果
                        {
                                damage += damage * lvl_emjy / 5000;
                                damage += damage * lvl_ngxy / 10000;
                                if (lvl_emjy > 1000 && lvl_ngxy > 1000 && !userp(target)) damage *= lvl_emjy / 1000 + lvl_ngxy / 1000;
                                if (lvl_emjy > 5000 && lvl_ngxy > 3500) {
                                        if ((lvl_emjy / 150) > 85) {//12000lv滿85% REMOTE_ATTACK
                                                if (random(100) < 86) flagremote = 1;
                                        } else {
                                                if (random(100) < (lvl_emjy / 150)) flagremote = 1;
                                        }
                                        damage += damage / 8;
                                        if (lvl_emjy > 8000 && lvl_ngxy > 5000) damage += damage / 7;
                                        if (lvl_emjy > 12000 && lvl_ngxy > 8000) damage += damage / 6;
                                        if (lvl_emjy > 16000 && lvl_ngxy > 12000) damage += damage / 5;
                                }
                                if ( 
                                        (int)me->query_skill("claw", 1) > 1000 && 
                                        (int)me->query_skill("jiuyin-baiguzhao", 1) > 1000 && 
                                        (me->query_skill_mapped("claw") == "jiuyin-baiguzhao") && 
                                        random( 2 + (int)(me->query_skill("jiuyin-baiguzhao", 1) / 3333) )
                                ) {
                                        switch(query("character", me) )
                                        {
                                                case "心狠手辣":
                                                        msg += NOR CYN "$N" NOR CYN "桀桀怪笑，虛晃一掌，倏的衝$n"
                                                        NOR CYN "頭頂抓下。\n" NOR;
                                                        break;
                                                case "陰險奸詐":
                                                        msg += NOR CYN "$N" NOR CYN "冷笑數聲，虛晃一掌，飛向$n"
                                                        NOR CYN "頭頂抓下。\n" NOR;
                                                        break;
                                                default:
                                                        msg += NOR CYN "$N" NOR CYN "揚聲吐氣，虛晃一掌，奮力向$n"
                                                        NOR CYN "頭頂抓下。\n" NOR;
                                                        break;
                                        }                                                                               
                                        if ( random((int)me->query_skill("jiuyin-baiguzhao", 1) * (query("jiali", me) + 1)) > (int)target->query_skill("parry", 1) / 2 && 
                                                        query("max_neili", me) > ( (userp(target)) ? query("max_neili", target) * 3 : query("max_neili", target) / 100 )
                                        ) {
                                                msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, ( (damage > query("max_qi", target)) ? query("max_qi", target) + 1 : damage  ), 
                                                90 + (int)me->query_skill("jiuyin-baiguzhao", 1) /50, 
                                                HIR "$N" HIR "這一爪來勢好快，正抓中$n"
                                                HIR "的檀中大穴，$n" HIR
                                                "一聲慘叫，軟綿綿的癱了下去。\n" NOR);
                                                flagclaw = 1;
                    } else {
                                                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 90 + (int)me->query_skill("jiuyin-baiguzhao", 1) /50, 
                                                HIR "$n" HIR "連忙躲閃，但“撲哧”一聲，$N"
                                                HIR "五指正插入$n" HIR "的手背。\n" NOR);
                    }
                                                target->affect_by("jy_poison",
                                                ([ "level" : query("jiali", me) / 50 + 200 + query("level", me) * 10,
                                                        "id":query("id", me),
                                                        "duration" : (int)me->query_skill("jiuyin-baiguzhao", 1) / 10 + query("level", me) ]));
                                                msg += NOR BLU "$n" BLU "突然只膝彎曲，身子慢慢垂下，口中發出似人似鬼的荷荷之聲。\n" NOR; 
                }
                                                                
                                if (flagclaw) {
                                        obs = me->query_enemy();
                                        obs = obs - ({target});
                                        if (!obs || !arrayp(obs) || !sizeof(obs))
                                                flagclaw = 0;
                                        else {  
                                                newtarget = obs[random(sizeof(obs))];
        ap = attack_power(me, "strike") +
                                me->query_skill("force") +
                                me->query_skill("martial-cognize") +
                                me->query_skill("force-cognize") +
                                me->query_skill("mahayana") * 3 + 
                                me->query_str()*(100+query("level",me));
        dp = defense_power(newtarget, "dodge") +
                                newtarget->query_skill("force") +
                                newtarget->query_skill("martial-cognize") +
                                newtarget->query_skill("force-cognize") +
                                me->query_con()*100;
        ap = ap + ap * lvl_jingxin / 600;                                               
        ap += ap*(ABILITY_D->check_ability(me, "ap_power-pxz-zhao"))/100; 
        if (newtarget->is_busy()) ap += ap / 6;
        if (BUFF_D->check_buff(me, "ljz_zhixin")) ap += ap / 8;
                                            if (ap + random(ap) < dp)
                                                        flagclaw = 0;
                                        }
                                }
                                        if (flagclaw) {
                                                message_combatd(msg, me, target);
                                                target = newtarget;
                                                                                        if (flagremote && !random(3)){
                                                                                                if (damage<query("eff_qi", target)/5) {
                                                                                                        target->receive_damage("qi", query("eff_qi", target)/5);
                                                                                                        target->receive_wound("qi", query("eff_qi", target)/5);
                                                                                                } else {
                                                                                                        target->receive_damage("qi", damage);
                                                                                                        target->receive_wound("qi", damage);
                                                                                                }
                                                                                        }
                                                msg = COMBAT_D->do_damage(me, target, (flagremote ? REMOTE_ATTACK : UNARMED_ATTACK), damage, 135 + lvl_jingxin /25 + lvl_emjy / 20, 
                                                        NOR CYN "$N" NOR CYN "大喝一聲，雙袖鼓盪起" + ((flagremote) ? BLINK : NOR) + HIW "峨眉九陽"  
                                                        NOR CYN + ((flagremote) ? "螺旋透勁" : "勁氣") + "，順勢往旁一推。\n" NOR
                                                        HIR "只聽轟然一聲巨響，$n" HIR "被$N"
                                                        HIR "一招正中，身子便如稻草般平平飛出"
                                                        "，重\n重摔在地下，嘔出一大口鮮血，動"
                                                        "也不動。\n" NOR);
                                        } else {
                                                                                        if (flagremote && !random(3)){
                                                                                                if (damage<query("eff_qi", target)/5) {
                                                                                                        target->receive_damage("qi", query("eff_qi", target)/5);
                                                                                                        target->receive_wound("qi", query("eff_qi", target)/5);
                                                                                                } else {
                                                                                                        target->receive_damage("qi", damage);
                                                                                                        target->receive_wound("qi", damage);
                                                                                                }
                                                                                        }
                                                msg += COMBAT_D->do_damage(me, target, (flagremote ? REMOTE_ATTACK : UNARMED_ATTACK), damage, 135 + lvl_jingxin /25 + lvl_emjy / 20, 
                                                NOR CYN "$N" NOR CYN "大喝一聲，雙袖鼓盪起" + ((flagremote) ? BLINK : NOR) + HIW "峨眉九陽"  
                                                NOR CYN + ((flagremote) ? "螺旋透勁" : "勁氣") + "，用力往前一推。\n" NOR
                                                HIR "只聽轟然一聲巨響，$n" HIR "被$N"
                                                HIR "一招正中，身子便如稻草般平平飛出"
                                                "，重\n重摔在地下，嘔出一大口鮮血，動"
                                                "也不動。\n" NOR);
                                                        }
                }
                else
                                        msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 145 + lvl_jingxin /25, 
                                                HIR "只聽轟然一聲巨響，$n" HIR "被$N"
                                                HIR "一招正中，身子便如稻草般平平飛出"
                                                "，重\n重摔在地下，嘔出一大口鮮血，動"
                                                "也不動。\n" NOR);
        } else
        {
                addn("neili", -500, me);
                me->start_busy(3);
                msg += CYN "可是$p" CYN "內力深厚，及時擺脫了"
                       CYN "$P" CYN "內力的牽扯，躲開了這一擊！\n" NOR;
        }
        message_combatd(msg, me, target);

                time = 20;
                time -= query("level", me) / 50;
                if (time < 15) time = 15;
                if ( BUFF_D->check_buff(me, "ljz-niepan") ) time -= 5;
                if( BUFF_D->check_buff(me, "ljz_fengyun") ) time /= 2;
                buff = ([
                "caster" : me,
                "target" : me,
                "type"   : "cooldown",
                "type2"  : "emaq_piaoxuezhao",
                "attr"   : "curse",
                "name"   : "飄雪穿雲掌·佛光普照",
                "time"   : time,
                "buff_msg" : "佛光普照消耗心神太甚，還需等待"+time+"秒方可再次施展。\n",
                "disa_msg" : "",
                "disa_type": 0,
                ]);
                BUFF_D->buffup(buff);
        
        return 1;
}

