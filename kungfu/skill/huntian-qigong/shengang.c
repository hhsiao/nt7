// This program is a part of NITAN MudLIB
// shengang.c 混天氣功混天神罡

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int exert(object me, object target)
{
        object weapon;
        string msg;
        int d_count, count, qi, maxqi, skill;
        mapping buff, data;

        weapon=query_temp("weapon", me);

        if( !query("can_exert/huntian-qigong/shengang", me) )
                return notify_fail(HIG "你還沒有受到某人的指點，還不會使用這種功夫。\n" NOR);

        if( BUFF_D->check_buff(me,"shield") )
                return notify_fail(HIG "你已經在運混元天罡了。\n" NOR);

        if( query("neili", me)<200 )
                return notify_fail("你的內力還不夠！\n");

        if( (int)me->query_skill("huntian-qigong", 1) < 150 )
                return notify_fail("你的混天氣功的修為不夠，不能使用混元天罡! \n");

        msg = WHT "$N使出混天氣功絕學「混元天罡」，一股白氣自頂心泥丸發散而下，全身瀰漫在白色薄霧中！\n" NOR;

        qi = query("qi", me);
        maxqi = query("max_qi", me);
        skill = (int) (me->query_skill("huntian-qigong", 1) / 6);
        count = me->query_str();
        d_count = (int)me->query_dex() / 2;

	        
        if( qi > (maxqi * 0.4) )
        {
                addn("neili", -150, me);
                
                data =  ([
                        "damage" : skill*20,
	                "unarmed_damage" : skill*20,
	                "attack": skill*2,
	                "defense":skill*2,
                        "dex" : skill/5,
	        ]);
                buff =
                ([
			"caster": me,
			"target": me,
			"type"  : "shield",
			"attr"  : "bless",
			"name"  : "混天氣功·混天神罡",
			"time"  : skill,
			"buff_data": data,	
			"buff_msg" : msg,
			"disa_msg" : "白色的薄霧漸漸散去，$N的身形步法又變的清晰可見。\n",
			"disa_type": 1,
                ]);

                BUFF_D->buffup(buff);
        
        } 
        else
        {
                msg = HIR "$N拼盡畢生功力想提起混元天罡，但自己受傷太重，沒能成功!\n" NOR;
                message_combatd(msg, me, target);
        }
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}
