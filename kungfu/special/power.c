// power.c 天神降世

#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIY "天神降世" NOR; }

int perform(object me, string skill) {
    mapping buff, data;
    string msg;
    int count;

    if(query("qi", me)<80 )
        return notify_fail("你的體力不支，無法迅猛提升自己的戰鬥力。\n");

    msg = HIY "$N" HIY "雙臂一伸一縮，膝部微彎，作勢欲撲。\n" NOR;

    count = me->query_str();

    if(BUFF_D->check_buff(me, "spe_power") )
        return notify_fail("你已經盡力提升自己的戰鬥力了。\n");

    me->receive_damage("qi", 40 + random(40));
    data = ([
        "attack": count*3
        ]);
    buff = ([
        "caster": me,
        "target": me,
        "type": "spe_power",
        "attr": "bless",
        "name": HIY "天神降世" NOR,
        "time": 60 + random(30),
        "buff_data": data,
        "buff_msg": msg,
        "disa_msg": "你施展完天神降世，鬆了一口氣。\n"
        ]);
    BUFF_D->buffup(buff);

    return 1;
}
