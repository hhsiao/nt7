// This is player's own skill (Write by Lonely@nt2)
// Create by 風林火山(Lxer) at Sat May 16 22:29:05 2015
// 風林火山劍(lxer-sword.c)

#include <ansi.h>
inherit SKILL;

int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
    ([
        "action": "$N左撓右撓，在腋窩搓一把汙泥抹在$w頂端,斜刺一招「蒼松迎客」對準$n饞涎欲滴的大嘴送去",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 100,
        "damage_type": "刺傷",
        "skill_name": "風林"
    ]),
// ZHAOSHI : 1
    ([
        "action": "$N撓了再撓，從腳底板上扣下來一塊汙泥塗在$w上,頓時一招「臭氣熏天」散發無窮威力,對準$n的胸口斜斜刺出一劍",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 110,
        "damage_type": "刺傷",
        "skill_name": "火山"
    ]),
// ZHAOSHI : 2
    ([
        "action": "$N身如鬼魅，手握$w,頓時一招「疾如風」對準$n的頸部斬落",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 120,
        "damage_type": "刺傷",
        "skill_name": "疾如風"
    ]),
// ZHAOSHI : 3
    ([
        "action": "$N嚴陣以待，手握$w,沉穩使出「徐如林」將$n暴風驟雨般的攻擊格擋回去",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 130,
        "damage_type": "刺傷",
        "skill_name": "徐如林"
    ]),
// ZHAOSHI : 4
    ([
        "action": "$N一聲怒吼，雙手緊攥$w,向前猛力揮舞，一招「侵略如火」洶湧直衝$n的上身要害攻擊",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 140,
        "damage_type": "刺傷",
        "skill_name": "侵掠如火"
    ]),
// ZHAOSHI : 5
    ([
        "action": "$N凝神靜氣，雙手緊握$w,對$n的所有障眼法全都不管不顧，只管使出「不動如山」對敵",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 150,
        "damage_type": "刺傷",
        "skill_name": "不動如山"
    ]),
// ZHAOSHI : 6
});

int valid_learn(object me) {
    object weapon;

    if(!objectp(weapon = query_temp("weapon", me) )
        || query("skill_type", weapon) != "sword" )
        return notify_fail("你使用的武器不對。\n");

    if(query("max_neili", me)<50 )
        return notify_fail("你的內力太弱，無法練" + "風林火山劍" + "。\n");

    return 1;
}

int valid_enable(string usage) {
    return usage == "sword" ||
        usage == "parry";
}

string query_skill_name(int level) {
    int i;
    for(i = sizeof(action) - 1; i >= 0; i--)
        if(level >= action[i]["lvl"])
        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon) {
    int i, level;
    level = (int)me->query_skill("lxer-sword", 1);
    for(i = sizeof(action); i > 0; i--)
        if(level > action[i - 1]["lvl"])
        return action[NewRandom(i, 20, level / 5)];
}

mixed *query_actions() { return action; }

int query_effect_parry(object attacker, object me) {
    int lvl;

    if(query_temp("weapon", me) )
        return 0;

    lvl = me->query_skill("lxer-sword", 1);
    if (lvl < 80)  return 0;
    if (lvl < 200) return 50;
    if (lvl < 280) return 80;
    if (lvl < 350) return 100;
    return 120;
}

int practice_skill(object me) {
    object weapon;
    if(!objectp(weapon = query_temp("weapon", me)) ||
        query("skill_type", weapon) != "sword" )
        return notify_fail("你使用的武器不對。\n");

    if(query("qi", me)<25 )
        return notify_fail("你的體力不夠了，休息一下再練吧。\n");

    if(query("neili", me)<3 )
        return notify_fail("你的內力不夠了，休息一下再練吧。\n");

    me->receive_damage("qi", 25);
    addn("neili", -3, me);
    return 1;
}

mixed hit_ob(object me, object victim, int damage) {
    mixed result;
    if (damage < 100) return 0;

    if (random(damage) > victim->query_str())
    {
        result = ([ "damage": damage ]);
        result += ([ "msg": HIW "你聽到「喀嚓」一聲輕響，已被$N的兵器所發殺氣挫傷，$n頓時血冒三丈！！！\n" NOR ]);

        return result;
    }
}

string perform_action_file(string action) {
    return __DIR__ + "lxer-sword" + "/" + action;
}
