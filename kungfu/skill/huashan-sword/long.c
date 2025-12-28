// This program is a part of NITAN MudLIB
// feilong.c 華山劍法「天外飛龍」
// written by Lonely@nt7

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return HIY "天外飛龍" NOR; }

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        int ap, dp;

        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("「天外飛龍」只能在戰鬥中對對手使用。\n");

        if( !objectp(weapon=query_temp("weapon", me)) ||
            query("skill_type", weapon) != "sword" )
                return notify_fail("不拿劍怎麼使用「天外飛龍」？\n");

        if( (int)me->query_skill("huashan-sword", 1) < 150 )
                return notify_fail("你華山劍法不夠嫻熟，使不出「天外飛龍」。\n");

        if( (int)me->query_skill("force") < 150 )
                return notify_fail("你內功火候不夠，使不出「天外飛龍」。\n");

        if( query("neili", me)<2000 )
                return notify_fail(HIC"你現在真氣不夠，無法將「天外飛龍」使完！\n"NOR);

        if( me->query_skill_mapped("sword") != "huashan-sword" )
                return notify_fail("你沒有激發華山劍法，無法使用「天外飛龍」。\n");
        
        msg = HIC "$N" HIC "一聲長嘯，急運內力，勒手仗劍，猛地向$n" HIC "擲出，霎那間風雲變色！\n" NOR;

        ap = attack_power(me, "sword");
        dp = defense_power(target, "dodge");
        
        if( ap / 2 + random(ap) > dp )
        {
                damage = -1;
                msg += HIR "只見一道銀色閃電劃破長空，正在$n" HIR "愣神間，"+query("name", weapon)+HIR "已經穿胸而入，將$n" HIR "狠狠釘在了地上！\n" NOR;
        } else
        if( ap > dp / 3 * 2 )
        {
                damage = damage_power(me, "sword") * 3;
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 90,
                                           HIC "$n" HIC "見狀大驚失色，急忙側讓躲避，誰知"+query("name", weapon)+
                                           HIC"來勢太快，只見一道銀光劃過，$n" HIC "腰腹鮮血洶湧而出！\n" NOR);
                addn("neili", -2000, me);
        } else
        {
                damage = 0;
                msg += CYN "然而$n" CYN "輕輕一笑，側身伸指，正彈"
                       "在$N" CYN "的劍脊上，劍斜飛落地。\n" NOR;
        }
        
        addn("neili", -2000, me);
        me->start_busy(3);
        if( !weapon->is_item_make() && !query("bind_owner", weapon) )
                weapon->move(environment(me));
        message_combatd(msg, me, target);
        if( damage == -1 ) target->die(me);
                
        return 1;
}
