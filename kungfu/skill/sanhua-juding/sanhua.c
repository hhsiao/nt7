
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        mapping buff, data;
        object weapon;
        int damage,skill,wap,wdp;
        string *limb, result, str,msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||        !target->is_character()
        ||        !me->is_fighting(target) )
                return notify_fail("三花聚頂只能對戰鬥中的對手使用。\n");

        if( BUFF_D->check_buff(me, "atkup") )
                return notify_fail("你已在使用三花聚頂了！\n");

        if( objectp(query_temp("weapon", me)) )
                return notify_fail("空手才能施展三花聚頂！\n");

        if( me->query_skill_mapped("strike") != "sanhua-juding" )
                return notify_fail("你所用的並非三花聚頂掌，不能施展三花聚頂！\n");

        if( me->query_skill_prepared("strike") != "sanhua-juding" )
                return notify_fail("你所備的並非三花聚頂掌，不能施展三花聚頂！\n");

        if( me->query_skill_mapped("force") != "xiantian-gong" )
                return notify_fail("你所用的並非先天功，施展不出三花聚頂！\n");

        if( me->query_skill("force") < 135 )
                return notify_fail("你的先天功火候未到，無法施展三花聚頂！\n");

        if( me->query_skill("strike") < 135 )
                return notify_fail("三花聚頂需要精湛的三花聚頂掌方能有效施展！\n");

        if( query("neili", me) <= 300 )
                return notify_fail("你的內力不夠使用三花聚頂！\n");
        if( query("jingli", me) <= 200 )
                return notify_fail("你的精力不夠使用三花聚頂！\n");        
        if( query("jing", me) <= 200 )
                return notify_fail("你的精不夠使用三花聚頂！\n");


        msg = HIM"$N運起玄門先天功，內力遍佈全身，頭頂冒出絲絲熱氣，竟然呈現三朵蓮花，緊跟劈出一掌，一股氣勁似浪潮一般向$n襲來！\n\n"NOR;

        skill =  ( me->query_skill("sanhua-juding")
                + me->query_skill("force") ) / 2;
        
        data = ([
                "attack" : skill/2,
                "defense": skill/2,
                "damage" : skill*2,
        ]);
        
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "atkup",
                "attr"  : "bless",
                "name"  : "三花聚頂掌·三花聚頂",
                "time"  : skill/15,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的三花聚頂運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);

                weapon=query_temp("weapon", target);

                  if( objectp(weapon) )
                {
                        wap=query("force", me)/5
                        +query("sanhua-juding", me)/5
                        + (int)me->query_str()
                        +query("jiali", me);

                        wdp = (int)weapon->weight() / 500
                        +query("rigidity", weapon )
                        + (int)target->query_str()
                        +query("jiali", target )
                        + (int)target->query_skill("parry")/3;

                        wap = wap/2 + random(wap/2);

                        if( wap > 3 * wdp ) {
                                message_vision(HIY"只見$N身上的$n"+HIY+"已被一掌震斷。\n"NOR, target, weapon);
                                weapon->unequip();
                                weapon->move(environment(target));
                                set("name", "斷掉的"+query("name", weapon), weapon);
                                set("value", 0, weapon);
                                set("weapon_prop", 0, weapon);
                                target->reset_action();
                                addn("neili", -150, me);//tobreakweapontakesmoreneili

                        } else if( wap > 2 * wdp ) {
                                message_vision(HIW"$N只覺得手中" + weapon->name() + "被一掌震得把持不定，脫手飛出！\n" NOR, target);
                                weapon->unequip();
                                weapon->move(environment(target));
                                target->reset_action();
                                addn("neili", -120, me);//tobreakweapontakesmoreneili

                        } else if( wap > wdp ) {
                                message_vision("$N只覺得手中" + weapon->name() + "一震，險些脫手！\n", target);
                                addn("neili", -100, me);//tobreakweapontakesmoreneili
                        }
                }
                else{
                        addn_temp("apply/attack", skill/2, me);
                        COMBAT_D->do_attack(me,target,query_temp("weapon", me));
                        addn_temp("apply/attack", -skill/2, me);
                }

        COMBAT_D->do_attack(me,target,query_temp("weapon", me));

        addn("neili", -skill/2, me);
        addn("jingli", -100, me);
        addn("jing", -100, me);
        me->start_busy(random(2));

        return 1;
}