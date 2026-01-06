// This is player's own skill (Write by Lonely@nt2)
// Create by 枯枝(Kuzhi) at Sun May 24 23:17:30 2015
// 魔心十劫指(moxin-finger.c)

#include <ansi.h>
inherit SKILL;

int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
    ([
        "action": "$N揮指橫掃，如魔行道，一式「魔道橫行」，自空中往$n的頭頂旋轉而至，凡過之處，全無生機可存。",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 100,
        "damage_type": "瘀傷",
        "skill_name": "魔道橫行"
    ]),
// ZHAOSHI : 1
    ([
        "action": "$N十指連環彈動，盡封$n七個大穴，使其難以動彈，最後以十成功力的一指更是如流星一樣而來。",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 110,
        "damage_type": "瘀傷",
        "skill_name": "魔踏七星"
    ]),
// ZHAOSHI : 2
    ([
        "action": "只見$N以勁隔空御力，一片天下蒼生在苦海沉浮，混亂顛倒，自相攻伐之象襲向$n。",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 120,
        "damage_type": "瘀傷",
        "skill_name": "魔隨空生"
    ]),
// ZHAOSHI : 3
    ([
        "action": "$N右臂緊伸，五指齊出，情未斷，路先斷，蘊含的魔氣直逼$n，氣勢逼人無比。",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 130,
        "damage_type": "瘀傷",
        "skill_name": "魔生情斷"
    ]),
// ZHAOSHI : 4
    ([
        "action": "萬劫浮生，是由怨怒推動的力量。只見$N指鋒急勁，削向四周空氣，產生了鬼泣的聲音。",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 140,
        "damage_type": "瘀傷",
        "skill_name": "群魔亂舞"
    ]),
// ZHAOSHI : 5
    ([
        "action": "只見從$N體內散出的陣陣魔氣，伴隨著無敵的氣勢攻向$n。",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 150,
        "damage_type": "瘀傷",
        "skill_name": "魔氣縱橫"
    ]),
// ZHAOSHI : 6
    ([
        "action": "這是$N包含蒼生對受神佛玩弄命運的仇恨反擊，拋棄一切，破天滅神，一怒斷佛，襲向$n。",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 160,
        "damage_type": "瘀傷",
        "skill_name": "魔梵般若"
    ]),
// ZHAOSHI : 7
    ([
        "action": "只見$N懸浮半空，入魔乃至屠去七情，魔更為魔，此招出後$n已無倖存之望。",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 180,
        "damage_type": "瘀傷",
        "skill_name": "魔極屠情"
    ]),
// ZHAOSHI : 8
    ([
        "action": "見血就會爆發屠殺的慾望，$N十指連戳，伴隨著魔勁，攻敵至亡。",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 200,
        "damage_type": "瘀傷",
        "skill_name": "血屠魔功"
    ]),
// ZHAOSHI : 9
});

int valid_learn(object me) {
    if(query_temp("weapon", me) || query_temp("secondary_weapon", me) )
        return notify_fail("練"+"魔心十劫指"+"必須空手。\n");
    if(query("max_neili", me)<50 )
        return notify_fail("你的內力太弱，無法練"+"魔心十劫指"+"。\n");
    return 1;
}

int valid_enable(string usage) {
    return usage == "finger" ||
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
    level = (int)me->query_skill("moxin-finger", 1);
    for(i = sizeof(action); i > 0; i--)
        if(level > action[i - 1]["lvl"])
        return action[NewRandom(i, 20, level / 5)];
}

mixed *query_actions() { return action; }

int query_effect_parry(object attacker, object me) {
    int lvl;

    if(query_temp("weapon", me) )
        return 0;

    lvl = me->query_skill("moxin-finger", 1);
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
        result += ([ "msg": HIW "你聽到「喀嚓」一聲輕響，已被$N所發殺氣挫傷，$n頓時血冒三丈！！！\n" NOR ]);

        return result;
    }
}

string perform_action_file(string action) {
    return __DIR__ + "moxin-finger" + "/" + action;
}
