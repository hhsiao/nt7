#include <ansi.h>

inherit F_SSERVER;

string name() { return HIW "參商劍氣" NOR; }

int perform( object me, object target)
{
        int lvl, str, dex, skill;
        string weapon;
        mapping buff, data;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("參商劍氣只能對戰鬥中的對手使用！\n");

        if( BUFF_D->check_buff(me, "atkup") )
                return notify_fail("你已經在使用參商劍氣了！\n");

        if( objectp(query_temp("weapon", me)) )
                        return notify_fail("參商劍氣需要你空手才能施展！\n");

        if( me->query_skill_mapped("finger") != "canhe-zhi" )
                return notify_fail("你所使用的並非參合指，不能施展參商劍氣！\n");

        if( me->query_skill_prepared("finger") != "canhe-zhi" )
                return notify_fail("你所備的並非參合指，不能施展參商劍氣！\n");

/*
     if( me->query_skill_mapped("force") != "shenyuan-gong" )
                return notify_fail("你所激發的內功並非神元功，施展不出參商劍氣！\n");
*/

        if( me->query_skill("force") < 140 )
                return notify_fail("你的內功火候不到，無法施展慕容家傳絕學！\n");

        if( me->query_int() < 22 )
                return notify_fail("你的悟性太差，不能施展姑蘇慕容家傳絕學！\n");

        if( (lvl=me->query_skill("finger")) < 100 )
                return notify_fail("參商劍氣需要精深的指力方能奏效！\n");

        if( query("neili", me) <= lvl*3/2 )
                return notify_fail("你的內力不足以使用慕容絕學參商指法！\n");

        if( query("jingli", me)<lvl )
                return notify_fail("你的精力不足以使用慕容絕學參商指法！\n");

        msg = HIM "$N" HIM "口中默唸“動靜如參商”，心隨意轉，勁跟力發。只聽得內力破空之聲呲呲作響！\n"
                        HIM "內力化作一股劍氣直奔"+target->name()+ HIM "射去！\n" NOR;

        str = me->query_skill("canhe-zhi",1)*2;
        dex = me->query_skill("beidou-xianzong" ,1)*2;
        skill = (str+dex) / 2;

        addn("neili", -lvl, me);
        addn("jingli", -lvl, me);

        data = ([
                "str" : str,
                "dex" : dex,
        ]);
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "atkup",
                "attr"  : "bless",
                "name"  : "參合指．參商劍氣",
                "time"  : skill/8,
                "buff_data": data,
                "buff_msg" : msg,
                "disa_msg" : "你緩緩收住身形，輕籲一口氣，將內力收回丹田。\n",

        ]);
        BUFF_D->buffup(buff);
        me->start_busy(1+random(2));
        return 1;
}
