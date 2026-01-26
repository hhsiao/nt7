// zhixin.c

#include <ansi.h>

int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int level = me->query_skill("linji-zhuang", 1);

        if (level < 60) return notify_fail("你的臨濟十二莊修為還不夠。\n");

        if( query("max_neili", me)<5*level )
                return notify_fail("你的內力還不夠強。\n");

        if( query("neili", me)<4*level )
                return notify_fail("你的真氣不夠。\n");

        if( query("eff_qi", me)<query("max_qi", me)/2 )
                return notify_fail("你已經受傷過重，只怕一運真氣便有生命危險！\n");

        if( BUFF_D->check_buff(me, "ljz_zhixin") )
                return notify_fail("你已經運用之心二莊凝聚心神了。\n");

        msg = HIY + "只見$N微一凝神，吞吐幾口長氣，一對眼眸靈動晶亮，神采弈弈。\n" NOR;

        addn("neili", -4*level, me);
        level += me->query_skill("literate", 1);
        level = 50+level/3+random(level/10);
        data = ([
                "int": level / 8,
        ]);
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "ljz_zhixin",
                "attr"  : "bless",
                "name"  : "臨濟十二莊．之心",
                "time"  : level,
                "buff_data": data,
                "buff_msg" : msg,
                "disa_msg" : HIG"你體內已積過多濁氣，似乎領悟力又歸於尋常。\n"NOR,

        ]);
        BUFF_D->buffup(buff);
        tell_object(me, HIY "你微一凝神，運動之心兩莊，去濁氣出體外，收清氣入心中，只覺靈臺清明，領悟力似乎有所增加。\n" NOR);

        return 1;
}
