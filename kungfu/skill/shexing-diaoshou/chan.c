// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return HIY "纏身決" NOR; }

int perform(object me, object target)
{
        mapping buff, data;
        string msg;
        int lvl, damage, itmp;
        int ap, dp;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name()+"只能對戰鬥中的對手使用。\n");

        if( query_temp("weapon", me) || query_temp("secondary_weapon", me) )
                return notify_fail(name()+"只能空手使用。\n");

        if ((int)me->query_skill("xiaoyaoyou", 1) < 150)
                return notify_fail("你的逍遙遊不夠嫻熟，不能使出"+name()+"！\n");

        if ((int)me->query_skill("shexing-diaoshou", 1) < 150)
                return notify_fail("你的蛇行刁手不夠嫻熟，不能使出"+name()+"！\n");

        if ((int)me->query_skill("huntian-qigong", 1) < 150)
                return notify_fail("你的混天氣功等級不夠，不能使出"+name()+"！\n");

        if( query("max_neili", me)<1000 )
                return notify_fail("你的內力太弱，不能使出"+name()+"！\n");

        if( query("neili", me)<300 )
                return notify_fail("你的內力太少了，不能使出"+name()+"！\n");

        /*
        if( !query_temp("gb_huixuan", me) )
                return notify_fail("你沒有使出逍遙迴旋步，無法使出纏身決！\n");
        */

                /*
        if (target->is_busy())
                return notify_fail("對方正在忙亂中，放心大膽攻擊吧！\n");
        */

        if( BUFF_D->check_buff(target, "sxds_diaoshou") && !target->is_busy() )
                return notify_fail(name()+"已經在對方身上發揮過了！\n");

        message_combatd(HIB "\n突然間$N口中發出“嘶嘶”的聲音，雙手半曲，三指上豎成蛇狀，\n"
                        "陪合著瀟遙步法，突然欺近$n的身邊，令$n大吃一驚。\n" NOR, me, target);
        addn("neili", -200+random(100), me);

                if(! BUFF_D->check_buff(target, "sxds_diaoshou") )
                {
                lvl = ((int)me->query_skill("xiaoyaoyou", 1) +
                   (int)me->query_skill("shexing-diaoshou", 1)) / 2;

                data = ([
                        "defense": -lvl/3,
                    "armor"  : -lvl/3, 
                ]);

                ap = attack_power(me, "hand");
                dp = defense_power(target, "dodge");
        
                itmp = (6000 - (int)me->query_skill("shexing-diaoshou", 1)) / 300;
                if (itmp<5) itmp=5;
                if (itmp>15) itmp=15;
        
                if( ap / 2 + random(ap) > dp )
                {
                        message_combatd(HIB "但見$N的身形有如蛇蠍纏身一般，環在$n的身邊，令$n不知所措，\n"
                                        "只覺的仿拂有無形的繩索慢慢的束縛了$n。\n" NOR, me, target);

                    target->start_busy(5);
                }

                buff = ([
                        "caster":me,
                        "target": target,
                        "type":"sxds_diaoshou",
                        "attr":"curse",
                    "name":"蛇形刁手·纏身決",
                        "time":  itmp * 2,
                    "buff_data":data,
                        "buff_msg": "",
                    "disa_msg": HIG "你使出渾身解數，算是掙脫了蛇形刁手的詭異怪招。\n" NOR,
                ]);
                BUFF_D->buffup(buff);
                me->start_busy(1);
                return 1;
        }

        if (target->is_busy())
        {
                ap = attack_power(me, "hand") + me->query_skill("shexing-diaoshou", 1);
                        dp = (defense_power(target, "dodge") + target->query_skill("parry", 1)) / 2;           
                if( ap / 2 + random(ap) > dp )
                {
                        me->start_busy(2);
                        target->stop_busy();
                        damage = damage_power(me, "hand") * 1 / 2;
                        damage+=query("jiali", me)*2/3;
                        
                        msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK,
                                           damage, 40,
                                           HIY "$n" HIY "一不留神，" HIY "小腹中了一記手刀，狂噴數口"HIR"鮮血"HIY"！\n"
                                           ":內傷@?");
                }
                else
                {
                        me->start_busy(3);
                        msg = HIY "$p" HIY "縱身一閃，躲開了$P" HIY "這一招！\n" NOR;
                }
                message_combatd(msg, me, target);
                return 1;
        }

        return 1;
}

