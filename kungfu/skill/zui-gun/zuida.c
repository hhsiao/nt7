// This program is a part of NITAN MudLIB
// zuida.c 少林醉棍 八仙醉打

#include <ansi.h>

inherit F_SSERVER;

string name() { return "八仙醉打"; }

int perform(object me, object target)
{
        mapping buff, data;
        object weapon;
        string msg;
        int count, count1, cnt, skill;

        if (! me->is_fighting())
                return notify_fail("「八仙醉打」只能在戰鬥中使用。\n");

        if( !objectp(weapon=query_temp("weapon", me)) ||
            query("skill_type", weapon) != "club" )
                return notify_fail("你使用的武器不對。\n");

        if( BUFF_D->check_buff(me, "zg_zuida") )
                return notify_fail("你已經在運功中了。\n");

        if( query_temp("powerup", me) )
                return notify_fail("你已經運起內功加力了，沒有更多的內力使用八仙醉打。\n");

        if ((int)me->query_str() < 25)
                return notify_fail("你現在的臂力不夠，目前不能使用此絕技！\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("你的內功火候不夠，難以施展此項絕技！\n");

        if ((int)me->query_skill("club") < 100)
                return notify_fail("你的棍法修為不夠，不會使用此項絕技！\n");

        if( query("neili", me)<500 )
                return notify_fail("你的真氣不足！\n");

        msg = HIY "$N" HIY "使出少林醉棍的絕技「八仙醉打」，臂"
              "力陡然增加, 身法陡然加快！\n" NOR;

        skill = me->query_skill("zui-gun",1);
        cnt =(int)( (int)me->query_condition("drunk") / 30);
        if( cnt > 50 ) cnt = 50;
        
        count=query("str", me)*random(cnt+2);
        count1=query("dex", me)*random(cnt+2);
        
        data = ([
                "str": count,
                "dex": count1,
        ]);
        buff = ([
                "caster": me,
                "target": me,
         "type"  : "zg_zuida", 
                "attr"  : "bless",
                "name"  : "醉棍·八仙醉打",
                "time"  : skill/3,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的八仙醉打運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);

        me->start_busy(2);

        addn("neili", -150, me);
        return 1;
}
