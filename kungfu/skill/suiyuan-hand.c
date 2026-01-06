// This is player's own skill (Write by Lonely@nt2)
// Create by 了盡(Zxahh) at Fri Feb 27 22:01:53 2015
// 隨緣手(suiyuan-hand.c)

#include <ansi.h>
inherit SKILL;

int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
    ([
        "action": "$N雙眼閉合，一手揮出，一切隨緣，卻不知為何一手按在了$n的心門上",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 100,
        "damage_type": "瘀傷",
        "skill_name": "一切隨緣"
    ]),
// ZHAOSHI : 1
    ([
        "action": "$N神色黯然，口中輕輕念著“君生我未生”，不知如何出現在了$n面前，手已經按在了$n的胸口。",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 110,
        "damage_type": "瘀傷",
        "skill_name": "君生我未生"
    ]),
// ZHAOSHI : 2
    ([
        "action": "$n定神一看，$N已經從眼前消失，“我生君已老”忽然在$N腦後響起，$n感毛骨悚然之時一股詭異內力從背後入侵攻入心脈！",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 120,
        "damage_type": "瘀傷",
        "skill_name": "我生君已老"
    ]),
// ZHAOSHI : 3
    ([
        "action": "$n正欲搶攻，但是這時$N整個人卻突然陷入了哀怨之中，口中喃喃念道“君恨我生遲”,讓$n遲疑了一下，下一刻$N的手輕輕的拂過了$n",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 130,
        "damage_type": "瘀傷",
        "skill_name": "君恨我生遲"
    ]),
// ZHAOSHI : 4
    ([
        "action": "$N突然面露猙獰，滔天恨意衝冠而起，不顧一切的一掌拍向了$n！",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 140,
        "damage_type": "瘀傷",
        "skill_name": "我恨君生早"
    ]),
// ZHAOSHI : 5
    ([
        "action": "$N忽然化作了一隻彩蝶飛過了$n的身邊，$n的耳中才留下了一句“化蝶去尋花”",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 150,
        "damage_type": "瘀傷",
        "skill_name": "化蝶去尋花"
    ]),
// ZHAOSHI : 6
    ([
        "action": "原本晃晃日光，但是$n的眼前如同陷入了黑夜，周圍被一片小草所包圍，芳草撫動中一聲似有似無的聲音傳來，“夜夜棲芳草”。",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 160,
        "damage_type": "瘀傷",
        "skill_name": "夜夜棲芳草"
    ]),
// ZHAOSHI : 7
    ([
        "action": "“只嘆緣難成”$N神色黯然的說道，手如同別離般輕輕揮動，一股柔和的內力拂過了$n。",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 180,
        "damage_type": "瘀傷",
        "skill_name": "只嘆緣難成"
    ]),
// ZHAOSHI : 8
    ([
        "action": "$N的手彷彿越過了空間抵達$n的胸前，口中呢喃著“只願來生緣”一句。",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 200,
        "damage_type": "瘀傷",
        "skill_name": "只願來生緣"
    ]),
// ZHAOSHI : 9
});

int valid_learn(object me) {
    if(query("max_neili", me)<50 )
        return notify_fail("你的內力太弱，無法練"+"隨緣手"+"。\n");
    return 1;
}

int valid_enable(string usage) {
    return usage == "hand" ||
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
    level = (int)me->query_skill("suiyuan-hand", 1);
    for(i = sizeof(action); i > 0; i--)
        if(level > action[i - 1]["lvl"])
        return action[NewRandom(i, 20, level / 5)];
}

mixed *query_actions() { return action; }

int query_effect_parry(object attacker, object me) {
    int lvl;

    if(query_temp("weapon", me) )
        return 0;

    lvl = me->query_skill("suiyuan-hand", 1);
    if (lvl < 80)  return 0;
    if (lvl < 200) return 50;
    if (lvl < 280) return 80;
    if (lvl < 350) return 100;
    return 120;
}

int practice_skill(object me) {
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
    return __DIR__ + "suiyuan-hand" + "/" + action;
}
