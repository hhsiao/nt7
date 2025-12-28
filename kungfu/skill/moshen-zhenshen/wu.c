// protect

#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return "無法無天"; }

int perform(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill;

        if( query("neili", me)<100 )
                return notify_fail("你的內力不夠。\n");

        if ((int)me->query_skill("moshen-zhenshen", 1) < 100)
                return notify_fail("你的魔神真身修為不夠。\n");

        if( BUFF_D->check_buff(me, "mszs_wu") ) 
                return notify_fail("你已經運起魔神真身絕招無法無天了。\n");

        skill = me->query_skill("force");
        addn("neili", -100, me);
        me->receive_damage("qi", 0);

        msg = HIY "$N" HIY "默運魔功，內勁在身體內快速的運轉，霎時在體外形成一層罡氣！\n" NOR;
        
        data = ([
                "armor" : skill/2,
                "defense": skill/3,
        ]);
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "mszs_wu",
                "attr"  : "bless",
                "name"  : "魔神真身·無法無天",
                "time"  : skill,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的無法無天運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;       
}
