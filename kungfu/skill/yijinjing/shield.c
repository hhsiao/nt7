// This program is a part of NT MudLIB
// shield.c 

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        int skill;
        string msg;
        mapping buff, data;

        if( query("family/family_name", me) != "少林派" && !query("yuanshen", me) )
                return notify_fail("你不是少林弟子，無法使用易筋經絕技。\n");

        if( target != me )
                return notify_fail("你只能用易筋經來激發金剛不壞體 \n");

        if( query("neili", me)<100 )
                return notify_fail("你的真氣不夠。\n");

        if( (int)me->query_skill("yijinjing", 1) < 40 )
                return notify_fail("你的易筋經等級不夠。\n");

        if( BUFF_D->check_buff(me, "shield") )
                return notify_fail("你已經在運功中了。\n");

        skill = me->query_skill("force");
        addn("neili", -100, me);
        me->receive_damage("qi", 0);

        msg = HIY "$N" HIY "雙目突然精芒暴漲,身上驀地湧起" HIY "一股凜冽金光。\n" NOR;

        data =  
        ([
	        "armor" : skill,
        ]);
	       
        buff =
        ([
                "caster": me,
                "target": me,
	        "type"  : "shield",
	        "attr"  : "bless",
	        "name"  : "易筋經·護體神功",
	        "time"  : skill,
	        "buff_data": data,	
	        "buff_msg" : msg,
	        "disa_msg" : "你的易筋經運行完畢，金光隱隱退去，你恢復原來的樣子。\n",
        ]);

        BUFF_D->buffup(buff);

        if( me->is_fighting() ) me->start_busy(2);

        return 1;
}
