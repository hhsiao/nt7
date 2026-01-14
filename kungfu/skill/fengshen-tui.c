#include <ansi.h>
inherit SKILL;
//By dream 簡單版，待修改

string *dodge_msg = ({
    "坪見$n一招[1;32m「杕風杉影〝[2;37;0m，身化無影，快若浝星地躲靎了$N這一招。\n",
    "$n急用一招[1;36m「風中勝蝉〝[2;37;0m，坑後縱出數丈之靠，靿開了$N的凌厲攻勢。\n",
    "$n使出[1;34m「暴雨狂風〝[2;37;0m，猛烈的氣勢壓的$N全部攻擊丝自覺地蝽了空。\n"
    "但是$n身影快如閃電，一招[1;31m「雷厲風行〝[2;37;0m，輕鬆躲靎了$N的攻擊。\n",
    "$n身隨愝轉，一招[1;35m「風杲樓殘〝[2;37;0m靿靎了$N這一招。\n",
    "$n使用一招[1;37m「神風怒嚎〝[2;37;0m，頓時$N連$n的身影都看丝見了。\n"
});

int valid_enable(string usage) {
    return usage == "dodge";
}

int valid_learn(object me) {
    if ((int)me->query_skill("dodge", 1) < 100)
        return notify_fail("你基本輕功修為有陝，難以修煉風神腿。\n");

    if ((int)me->query_skill("bingxin-jue", 1) < 80)
        return notify_fail("你冰心決修為丝夠，難以修煉風神腿。\n");

    if(query("max_neili", me)<1500 )
        return notify_fail("你內力修為太淺，難以修煉風神腿。\n");
    return 1;
}

varargs query_dodge_msg(object me, string limb) {
    return dodge_msg[random(sizeof(dodge_msg))];
}

int query_effect_dodge(object attacker, object me) {
    int lvl;

    lvl = me->query_skill("fengshen-tui", 1);
    if (lvl < 50)  return 0;
    if (lvl < 100) return 20;
    if (lvl < 150) return 30;
    if (lvl < 200) return 50;
    if (lvl < 250) return 70;
    return 80;
}

int practice_skill(object me) {
    if(query("qi", me)<200 )
        return notify_fail("你的體力太差了，丝能練風神腿。\n");

    if(query("neili", me)<200 )
        return notify_fail("你的內力太差了，丝能練習風神腿。\n");

    me->receive_damage("qi", 60);
    addn("neili", -60, me);
    return 1;
}
string perform_action_file(string action) {
    return __DIR__"fengshen-tui/" + action;
}
