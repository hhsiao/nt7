// Written by Lonely@nitan.org
// 鳳凰涅磐 轉世技能

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target)
{
        int skill;
        mapping buff, data;
        string msg;
        int time;

        if( userp(me) && !query("can_exert/linji-zhuang/niepan", me) )
                return notify_fail("你未得高人指點，不知該如何施展鳳凰涅磐。\n");

        /*
        if( query("family/family_name", me) != "峨嵋派" )
                return notify_fail("你不是峨嵋弟子，無法使用鳳凰涅磐。\n");
        */
        if( userp(me) && !query("yuanshen", me) )
                return notify_fail("你尚未悟道，無法使用鳳凰涅磐！\n");

        skill = me->query_skill("linji-zhuang", 1);
        if( skill < 1000 )
                return notify_fail("你的臨濟十二莊修為還不夠，無法使用鳳凰涅磐！\n");

        if( query("jingli", me)<1000 )
                return notify_fail("你的真氣不夠。\n");

        if( query("neili", me)<2000 )
                return notify_fail("你的內力不夠。\n");

        if( objectp(target) && target != me ) {
                if( !target->query_weak() )
                        return notify_fail(target->name() + "並沒有處於虛弱狀態。\n");

                addn("neili", -1000, me);
                me->receive_damage("qi", 0);
                target->clear_weak();
                message_combatd(HIY "只見$N" HIY "屏息靜氣，雙掌貼在"+target->name()+"背後，交錯運行大小二莊，只見"+target->name()+"全身被紫芒籠罩。\n" NOR, me);
                tell_object(target, HIG"\n你感覺身體狀態慢慢的復原了。。。\n\n" NOR);
                tell_object(me, HIG"\n你替"+target->name()+"消除了虛弱狀態。。。\n\n" NOR);
                if( me->is_fighting() ) me->start_busy(3);
                return 1;
        }

        if( BUFF_D->check_buff(me, "ljz-niepan") )
                return notify_fail("你已經在運起鳳凰涅磐了。\n");

        if( userp(me) )
        {
                if( (time = BUFF_D->get_buff_overtime(me, "ljz_niepan")) > 0 )
                        return notify_fail(MAG"神光離合消耗心神太甚，還需等待"+time+"秒。\n"NOR);
        }

        addn("neili", -1000, me);
        me->receive_damage("qi", 0);

        msg = HIY "$N" HIY "神色忽而歡嘆、忽而憂心、轉瞬間又化做不喜不悲之狀，\n隨著$N"
              HIY "張開眼神，一屢精光乍現及逝，$N"HIY"的氣習卻已全然不同。\n" NOR;

        data = ([
                "avoid_busy": 90,
                "avoid_weak": 90,
                "reduce_damage": 70,
        ]);

        buff = ([
                "caster": me,
                "target": me,
                "type"  : "ljz-niepan",
                "attr"  : "bless",
                "name"  : "臨濟十二莊．鳳凰涅磐",
                "time"  : skill/5,
                "buff_data": data,
                "buff_msg" : msg,
                "disa_msg" : "你的臨濟十二莊運行完畢，將內力收回丹田。\n",

        ]);
        BUFF_D->buffup(buff);

        time  = skill/5 + 40;
        time -= ABILITY_D->check_ability(me, "cd-ljz-niepan"); // ab門派減cd
        time -= ABILITY_D->check_ability(me, "reduce_cd", 2); // talent減cd

        buff =
	([
	        "caster" : me,
	        "target" : me,
	        "type"   : "cooldown",
	        "type2"  : "ljz_niepan",
	        "attr"   : "curse",
	        "name"   : "臨濟十二莊．鳳凰涅磐",
	        "time"   : time,
	        "buff_msg" : "鳳凰涅磐消耗心神太甚，還需等待"+time+"秒方可再次施展。\n",
	        "disa_msg" : "",
	        "disa_type": 0,
	]);
	BUFF_D->buffup(buff);
        if( me->is_fighting() ) me->start_busy(2);

        return 1;
}
