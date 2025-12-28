// snowyu piaomiao

#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object me);
void checking(object me);

string name() { return "雲煙飄渺"; }

int perform(object me, object target)
{
        mapping buff, data;
        string msg;
        int lvl, att, dam;

        lvl = (int)me->query_skill("wuluo-zhang", 1);
        att = lvl/4+ random(lvl/2);
        dam = lvl/2 + random(lvl/2);

        if( !target ) target = offensive_target(me);

        if( query("family/family_name", me) != "段氏皇族" && !wizardp(me) )
                return notify_fail(HIW "你非大理弟子無法施展「雲煙飄渺」！\n" NOR);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(HIW "雲煙飄渺只能對戰鬥中的對手使用。\n");

        if( me->query_skill("force") < 200 )
                return notify_fail(HIW "你的內功火候未到！\n");

        if( me->query_skill("wuluo-zhang", 1) < 150 )
                return notify_fail(HIW "你的基本五羅輕煙掌尚未純熟，無法施展雲煙飄渺！\n");

        if( me->query_skill("strike", 1) < 150 )
                return notify_fail(HIW "你的基本掌法尚未純熟，無法施展雲煙飄渺！\n");

        if( me->query_skill_mapped("force") != "kurong-changong")
                return notify_fail(HIW "你所用的內功心法不是枯榮禪功，無法聚集真氣。\n");

        if( query("max_neili", me) <= 2000 )
                return notify_fail(HIW "你的內力修為不足，無發體會出雲煙飄渺！\n" NOR);

        if( query("neili", me)<800 )
                return notify_fail(HIW "你的內力不夠，內勁不足以施展雲煙飄渺！\n" NOR);

        if( BUFF_D->check_buff(me, "wlz_piaomiao") )
                return notify_fail(HIW "你正在使用雲煙飄渺！\n");

        msg = HIB"$N運起內功心法，將真氣凝聚運往手掌，頓時$N手掌反白，掌中泛起一陣"NOR HIW"白煙"NOR HIB"。\n" NOR;

        addn("neili", -200, me);
        
        data = ([
                "attack": att,
                "unarmed_damage": dam,
        ]);
        
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "wlz_piaomiao",
                "attr"  : "bless",
                "name"  : "五羅輕煙掌·雲煙飄渺",
                "time"  : lvl/10,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你收起了聚起的內勁，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);
        
        COMBAT_D->do_attack(me, target, query_temp("weapon", me));

        call_out("checking", 1, me);
        return 1;
}

void checking(object me)
{
        if( !living(me) || me->is_ghost()  )
        {
                remove_effect(me);
                return;
        }

        if( !me->is_fighting() )
        {
                remove_effect(me);
                tell_object(me, MAG "\n你將氣息調節至原本的狀態。\n\n"NOR);

                return;
        }
        
        remove_call_out("checking");
        call_out("checking", 1, me);
        return;
}

void remove_effect(object me)
{
        if( !me ) return;
        
        BUFF_D->debuff(me, "wlz_piaomiao", 1);
}
