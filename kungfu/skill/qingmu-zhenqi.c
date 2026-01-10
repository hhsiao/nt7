//大木真氣
// redl 2014
#include <ansi.h>;

inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

//青木白金離火玄水厚土
string name() { return HIG "青木真氣" NOR; }

// int valid_learn(object me)
// {
//         return notify_fail( name() + HIC "無法通過簡單學習獲得提升。\n" NOR);
// }

int valid_research(object me) {
    if(query("max_neili", me)<100000 )
        return notify_fail("你的內力不夠。\n");
    if(me->query_skill("huisheng-jue", 1 )<2000 )
        return notify_fail("你的回生訣等級不夠。\n");
    if(query("level", me)<50 )
        return notify_fail("你的人物等級不夠。\n");
    if (me->query_skill("martial-cognize", 1) < me->query_skill("damu-zhenqi", 1))
        return notify_fail("你的武學修養太差。\n");
    if(query("gcjinchuan_yuancizhenqi/2", me)<1 )
        return notify_fail(HIC "你修行"+ name() + HIC "需要的木行元磁力不夠。\n" NOR);
    tell_object(me, NOR "你從身體裡逼起一股木行元磁力，緩緩運行周身經脈。\n" NOR);
    addn("gcjinchuan_yuancizhenqi/2", -1, me);
    return 1;
}

int valid_enable(string usage) { return usage == "taoism"; }

int difficult_level() {
    return 2800;
}

string perform_action_file(string action) {
    return __DIR__"qingmu-zhenqi/"+ action;
}

int help(object me) {
    write(HIC"\n"+name() + HIC"："NOR"\n");
    write(@HELP
    據說是上古句芒氏族的修行功法，借元磁力修煉，可以恢復氣血，並大幅提高精氣。
        學習要求：
                等級50
                內力100000
                回生訣2000
HELP
    );
    return 1;
}
