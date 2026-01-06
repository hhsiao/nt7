// This is player's own skill (Write by Lonely@nt2)
// Create by 劍人(Dlf) at Fri Feb 27 13:27:06 2015
// 龍鳳劍(longfeng-sword.c)

#include <ansi.h>
inherit SKILL;

int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
    ([
        "action": "$N縱身一躍，手握$w,頓時一招「臨」對準$n的$l斜斜刺出一劍",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 100,
        "damage_type": "刺傷",
        "skill_name": "臨"
    ]),
// ZHAOSHI : 1
    ([
        "action": "HIW\n忽然間$NHIW身形猛轉，剎時狂風如潮，遮雲蔽日，天地為之變色，這正是《龍鳳劍譜》所記載絕學「HIR兵式HIW」。轉眼間$NHIW已不見了蹤影，只聽得一聲尖嘯，一道白光從天而下將$nHIW籠罩！NOR",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 110,
        "damage_type": "刺傷",
        "skill_name": "兵"
    ]),
// ZHAOSHI : 2
    ([
        "action": "$N身形一轉，一招「鬥」$w劍光不定，斬向$n",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 120,
        "damage_type": "刺傷",
        "skill_name": "鬥"
    ]),
// ZHAOSHI : 3
    ([
        "action": "$N舞動$w，一招「者」迅捷無倫地劈向$n",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 130,
        "damage_type": "刺傷",
        "skill_name": "者"
    ]),
// ZHAOSHI : 4
    ([
        "action": "$N提劍過肩，蓄勁發力，一招「皆」直劈$n",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 140,
        "damage_type": "刺傷",
        "skill_name": "皆"
    ]),
// ZHAOSHI : 5
    ([
        "action": "$N移步側身，使一招「陣」劍光霍霍斬向$n",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 150,
        "damage_type": "刺傷",
        "skill_name": "陣"
    ]),
// ZHAOSHI : 6
    ([
        "action": "$N金刃劈風，$w隨著一招「騰蛟起風」由下而上撩往$n",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 160,
        "damage_type": "刺傷",
        "skill_name": "列"
    ]),
// ZHAOSHI : 7
    ([
        "action": "$N突然躍起丈餘，$n一抬頭，發現空中並無$N的身影，而一股寒氣卻從後襲來。",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 180,
        "damage_type": "刺傷",
        "skill_name": "在"
    ]),
// ZHAOSHI : 8
    ([
        "action": "$N一聲冷笑，一招「前」驀地裡疾衝上前，當真是動如脫兔，一瞬之間，與$n相距已不到一尺，兩人的鼻子幾乎要碰在一起。",
        "attack": 260,
        "damage": 260,
        "force": 260,
        "dodge": 260,
        "parry": 260,
        "lvl": 200,
        "damage_type": "刺傷",
        "skill_name": "前"
    ]),
// ZHAOSHI : 9
});

int valid_learn(object me) {
    object weapon;

    if(!objectp(weapon = query_temp("weapon", me) )
        || query("skill_type", weapon) != "sword" )
        return notify_fail("你使用的武器不對。\n");

    if(query("max_neili", me)<50 )
        return notify_fail("你的內力太弱，無法練" + "龍鳳劍" + "。\n");

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
    level = (int)me->query_skill("longfeng-sword", 1);
    for(i = sizeof(action); i > 0; i--)
        if(level > action[i - 1]["lvl"])
        return action[NewRandom(i, 20, level / 5)];
}

mixed *query_actions() { return action; }

int query_effect_parry(object attacker, object me) {
    int lvl;

    if(query_temp("weapon", me) )
        return 0;

    lvl = me->query_skill("longfeng-sword", 1);
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
    return __DIR__ + "longfeng-sword" + "/" + action;
}
