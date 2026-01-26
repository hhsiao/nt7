// This program is a part of NT MudLIB
// wuzhuan.c 奇門五轉

#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_SSERVER;

int exert(object me, object target)
{
        string msg;
        int i, extra,time;
        mapping buff, data;

        if( me->query_skill_mapped("force") != "bibo-shengong")
                return notify_fail("你所用的內功與「奇門五轉」心法相悖！\n");

        if( me->query_skill("bibo-shengong", 1) < 100 )
                return notify_fail("你的內功修為火候未到，還未領悟「奇門五轉」！\n");

        if( query("neili", me)<500 )
                return notify_fail("你的內力不夠，勁力不足以施展「奇門五轉」！\n");

        if( me->query_skill("qimen-wuxing", 1) < 1200 )
                return notify_fail("你的奇門五行修為不夠，還未領悟「奇門五轉」！\n");

        if( BUFF_D->check_buff(me, "dodgeup") )
                return notify_fail("你正在運用「奇門五轉」心法！\n");

        msg = HIG "$N臉上青氣大盛，腳下緩緩踩著九宮八卦方位，頭頂冒出騰騰白氣，";
        msg += "四面隱隱傳來潮湧之聲，碧波神功已發揮到極致！\n"NOR;

        addn("neili", -200, me);
        time = me->query_con()*2;
        extra = (int)me->query_skill("qimen-wuxing",1)* query("int",me);
                extra+= (int)me->query_skill("qimen-wuxing",1)*me->query_int()/10000;
        data = ([
                "attack" : extra/2,
                "defense": extra/2,
                "dodge"  : extra,
        ]);
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "dodgeup",
                "attr"  : "bless",
                "name"  : "碧波神功．奇門五轉",
                "time"  : time,
                "buff_data": data,
                "buff_msg" : msg,
                "disa_msg" : "$N只覺真氣運轉不暢，不得不放慢步法，調息吐納。\n",
                "disa_type":1,

        ]);
        //set_temp("wuzhuan_hit", extra/60+random(2), me);
        BUFF_D->buffup(buff);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}
