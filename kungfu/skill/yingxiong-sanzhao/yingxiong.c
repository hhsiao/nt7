// yingxiong.c

#include <ansi.h>
inherit F_SSERVER;

string name() { return "蓋世英雄"; }

int perform(object me, object target)
{
        mapping buff, data;
        int level;
        string msg;
        int ap, dp;

        if( !objectp(target) ) { target = offensive_target(me);}

        if( !target || !target->is_character() || target == me ||
            !me->is_fighting(target) ||
            !living(target) || query_temp("no_living", target) )
                return notify_fail(name() + "只能對戰鬥中的對手使用。\n");

        if( query("gender", me) != "男性" && !wizardp(me) )
                return notify_fail("象你這副娘娘腔，也許練“絕世風姿”恐怕更合適點吧。\n");

        if( (int)me->query_skill("yingxiong-sanzhao", 1) < 150 )
                return notify_fail("你的英雄三招不夠嫻熟，不會使用"+name()+"。\n");

        if( (int)me->query_skill("force", 1) < 160 )
                return notify_fail("你的基本內功不夠嫻熟，不會使用"+name()+"。\n");

        if( query("neili", me)<300 )
                return notify_fail("你的內力不足，恐怕沒法逞英雄了。\n");

        if( BUFF_D->check_buff(me, "yxsz_yingxiong") )
                return notify_fail("你已經在大擺英雄的譜了，還不夠啊？\n");

        level = me->query_skill("yingxiong-sanzhao", 1);
        addn("neili", -200, me);
        me->start_busy(1);

        ap = attack_power(me, "strike");
        dp = defense_power(target, "force");
        if( ap / 2 + random(ap) > dp )
        {
                msg = HIY"$N"HIY"越鬥越是兇猛，激鬥中仰天大吼一聲：“蓋世英雄！！”，一股豪氣自$N心中升起，頓時更是兇悍起來。\n" NOR;
                data = ([
                        "attack": level/2,
                        "unarmed_damage": level*2,
                ]);
                buff = ([
                        "caster": me,
                        "target": me,
                        "type"  : "yxsz_yingxiong",
                        "attr"  : "bless",
                        "name"  : "英雄三招·蓋世英雄",
                        "time"  : level/10,
                        "buff_data": data,      
                        "buff_msg" : msg,
                        "disa_msg" : HIY"$N突然感到心底一陣失落：“歷代英雄，都歸孤冢。”一念及此，頓時意興蕭然。\n" NOR,
                        "disa_type": 1,
                        
                ]);
                BUFF_D->buffup(buff);
                if( !target->is_busy() )
                        target->start_busy(random(3)+1);
        }
        else
        {
                message_combatd(HIG"激鬥中的$N衝著$n大喊：“蓋世。。。”，語意未了，就被$n迫得手忙腳亂。\n" NOR, me, target);
        }
        return 1;
}
