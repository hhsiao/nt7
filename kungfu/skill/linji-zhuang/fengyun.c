
// fengyun.c

#include <ansi.h>

int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int level = me->query_skill("linji-zhuang", 1);

        if (level < 120) return notify_fail("你的臨濟十二莊修為還不夠。\n");

        if( query("max_neili", me)<5*level )
                return notify_fail("你的內力還不夠強。\n");

        if( query("neili", me)<4*level )
                return notify_fail("你的真氣不夠。\n");

        if( query("eff_qi", me)<query("max_qi", me)/2 )
                return notify_fail("你已經受傷過重，只怕一運真氣便有生命危險！\n");

        if( BUFF_D->check_buff(me, "ljz_fengyun") )
                return notify_fail("你此時四肢百骸真氣鼓盪，不必再次運功。\n");

        msg = HIY + "只見$N微閉雙眼，身旁凝起一圈白霧，瞬息間一股旋風捲過，$N身形又復清晰。\n" NOR;

        addn("neili", -level, me);
        level /= 10;

        data = ([
                "dex": level,
                "attack": -level/2,
                "armor" : level*15,
                "defense": level*5,
        ]);

        buff = ([
                "caster": me,
                "target": me,
                "type"  : "dodgeup",
                "type2"  : "ljz_fengyun",
                "attr"  : "bless",
                "name"  : "臨濟十二莊．風雲",
                "time"  : level*10,
                "buff_data": data,
                "buff_msg" : msg,
                "disa_msg" : "你的臨濟十二莊運行完畢，將內力收回丹田。\n",

        ]);
        BUFF_D->buffup(buff);

        tell_object(me, HIY "你暗運風雲兩莊，心思浮雲飄空之悠閒緩慢，默想狂風蕩地之迅速緊急，\n一股丹田熱氣分注四肢百骸，但覺身手敏捷了許多。\n" NOR);
        if (me->is_fighting()) me->start_busy(2);
        return 1;
}
