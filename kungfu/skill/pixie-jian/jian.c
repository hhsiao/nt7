#include <ansi.h>
#include <combat.h>
string name() { return HIW "辟邪劍影" NOR; }

inherit F_SSERVER;
string *loc = ({"身前","身後","身左","身右","頭頂","腳下",});
string *limbs = ({"頭部", "頸部", "胸口", "後心","小腹", }); 
int perform(object me, object target)
{
        string msg,name;
        object weapon;
        int damage,fmsk,skill,ap,dp,delta,count,i,flagremote;
        if( !query("yuanshen", me) && userp(me) )
                return notify_fail("你還沒有悟道，還不能體會到" + name() + "的奧秘。\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }
        
        if( userp(me) && query("gender", me) != "無性" && !query("special_skill/ghost",me))
                return notify_fail("你試著修煉辟邪劍法，霎時只覺內息忽然大亂，幾欲焚身！\n");
                
        if (! me->is_fighting(target))
                return notify_fail(name() + "只能對戰鬥中的對手使用。\n");

        if( me->is_busy() )
                return notify_fail("你正忙著呢。\n");

        if (! objectp( weapon=query_temp("weapon", me)))
                return notify_fail("你使用的武器不對，難以施展" + name() + "。\n");

        if( weapon && query("skill_type", weapon) != "sword" && 
            query("skill_type", weapon) != "pin" )
                return notify_fail("你使用的武器不對，難以施展" + name() + "。\n");

        skill = me->query_skill("kuihua-xinfa", 1);
        fmsk = me->query_skill("richu-dongfang", 1);
        if (skill < 1000)
                return notify_fail("你的辟邪劍法不夠嫻熟，難以施展" + name() + "。\n");

        if (me->query_skill("dodge", 1) < 1000)
                return notify_fail("你基本輕功不夠嫻熟，難以施展" + name() + "。\n");

        if( query("neili", me)<100000 )
                return notify_fail("你現在的真氣不足，難以施展" + name() + "。\n");

        if (me->query_skill_mapped("sword") != "pixie-jian")
                return notify_fail("你沒有激發辟邪劍法，難以施展" + name() + "。\n");

        if (me->query_skill_mapped("force") != "kuihua-xinfa")
                return notify_fail("你沒有激發葵花心法，難以施展" + name() + "。\n");
        if (! living(target))
                return notify_fail("對方都已經這樣了，用不著這麼費力吧？\n");

        msg = HIR "$N" HIR "身形一轉，手中" + weapon->name() + HIR "寒光閃爍，猛然間，化作"
              "萬千劍影射向$n" HIR "，正是江湖中失傳已久的驚世奇學「辟邪劍影」！\n" NOR;
                
        message_combatd(sort_msg(msg), me, target);
        if(skill > 5000) flagremote = SPECIAL_ATTACK;
        if(skill > 10000) flagremote = REMOTE_ATTACK;       
        
        count = skill*100;

        addn_temp("apply/attack", count*2, me);
        addn_temp("apply/damage", count, me);
        addn_temp("apply/add_blind", 60, me);
        
        damage = damage_power(me, "sword");
        damage+= query("jiali", me);
        damage+= me->query_all_buff("damage");
        damage+= damage / 300 * me->query_str();
        damage/= 2;             
        damage += damage * (fmsk/100)* 5 / 100;
        
        ap = attack_power(me, "sword");
        dp = defense_power(target,"dodge");
        ap*=2;
        
        delta = ABILITY_D->check_ability(me, "power-pxj-jian"); // 門派ab
        if( delta )
        {       
            damage += damage*delta/100;
            ap += ap*delta/100;     
        }
        
        for (i = 0; i < 12; i++)
        {
            if (! me->is_fighting(target))
                break;
            if (! living(target))
                break;
            if (random(2) == 0 && ! target->is_busy())
                target->start_busy(1);
                
            if (ap / 2 + random(ap) > dp)
            {
                if(random(query("dex",target)) > 10 || fmsk > 2000)
                {
                    switch(random(9))
                    {
                        case 0:
                        case 4:
                        case 5:
                        case 6:
                                if( !query_temp("block_msg/all", target) )
                                {
                                    set_temp("block_msg/all", 1, target);
                                    call_out("cimu_end", 20, me, target);
                                    message_combatd(HIR "$N" HIR "只覺雙目一陣劇痛，眼前一黑，就什麼"
                                               "也看不見了，頓時長聲痛極而呼。\n" NOR, target, me);
                                }
                                break;
                        case 1:
                                if (! target->query_condition("no_perform"))
                                {
                                    target->apply_condition("no_perform", 5);
                                    call_out("poyuan_end", 15, me, target);
                                    message_combatd(HIR "$N" HIR "只覺眼前寒芒一閃而過，隨即全身一陣"
                                                "刺痛，幾股血柱自身上射出。\n$N陡然間一提真氣，"
                                                "竟發現周身力道竟似渙散一般，全然無法控制。\n" NOR, target,me);
                                }
                                break;
                        case 2:
                                set("jiali", 0, target);
                                break;
                        case 3:
                                if (! target->query_condition("no_exert"))
                                {                       
                                    target->apply_condition("no_exert", 1);
                                    call_out("exert_end", 30, me, target);
                                    message_combatd(HIR "$N" HIR "只覺寒光逼人，隨即全身一陣"
                                                "刺痛，氣門已傷。\n$N陡然間一提真氣，"
                                                "竟發現周身穴道具痛無比。\n" NOR, target,me);
                                }
                                break;
                        default:
                                if (! target->is_busy())
                                        target->start_busy(8);                          
                                break;
                    }
                }
                msg = HIW "$N"HIW"的身影出現在$n"HIW"的"+loc[random(sizeof(loc))]+"，$n" HIW "眼前劍光一閃，消失...\n\n"NOR;
                msg+= COMBAT_D->do_damage(me, target, flagremote, damage, 200+fmsk/10,
                                              HIR+HBRED "\n突然間，$n"HIW+HBRED+limbs[random(sizeof(limbs))]+HIR"的幾處大穴上，多了一些個細小紅點，微微有血滲出!\n" NOR);
                message_combatd(msg, me, target);
                damage+= damage/10;
                ap+= ap/20;
                addn("neili", -800, me);
                if( i< 11 )
                message_combatd(MAG"一招命中，$N"NOR+MAG"攻勢大盛。\n"NOR, me, target);
            }
            else 
            {
                msg = CYN "但是，$N找不到機會出手！\n" NOR;
                addn("neili", -200, me);
                message_combatd(msg, me, target);
            }
        }
        if (random(5) != 1)
                me->start_busy(1 + random(3));
        addn_temp("apply/attack", -(count*2), me);
        addn_temp("apply/damage", -count, me);
        addn_temp("apply/add_blind", -60, me);
        return 1;
}
void cimu_end(object me, object target)
{
        if( target && query_temp("block_msg/all", target) )
        {
                if (living(target))
                {
                        message_combatd(HIC "$N" HIC "抹了抹流著的"
                                        HIR "鮮血" HIC "，終於能看"
                                        "見了。\n" NOR, target);

                        tell_object(target, HIR "你終於抹掉了眼前的"
                                            "鮮血，能看見了。\n" NOR);
                }
                delete_temp("block_msg/all", target);
        }
        return;
}
void poyuan_end(object me, object target)
{
        if (target && target->query_condition("no_perform"))
        {
                if (living(target))
                {
                        message_combatd(HIC "$N" HIC "深深吸入一口"
                                        "氣，臉色由白轉紅，看起來好"
                                        "多了。\n" NOR, target);

                        tell_object(target, HIY "你感到被擾亂的真氣"
                                            "慢慢平靜了下來。\n" NOR);
                }
                target->clear_condition("no_perform");
        }
        return;
}
void exert_end(object me, object target)
{
        if (target && target->query_condition("no_exert"))
        {
                if (living(target))
                {
                        message_combatd(HIC "$N" HIC "深深吸入一口"
                                        "氣，臉色由白轉紅，看起來好"
                                        "多了。\n" NOR, target);

                        tell_object(target, HIY "你感到周身穴道不再疼痛，輕鬆多了。\n" NOR);
                }
                target->clear_condition("no_exert");
        }
        return;
}


