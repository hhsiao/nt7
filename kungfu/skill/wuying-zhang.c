// wuying-zhang.c
// 唐門 無影穿心掌

inherit SKILL;

mapping *action = ({
    ([
        "action": "$N連續上步，一式「五毒穿心」，右手抓向$n的$l",
        "force": 10,
        "dodge": 20,
        "damage_type": "瘀傷"
    ]),
    ([
        "action": "$N縱身一躍，一招「無影攝魂」，雙掌撲向$n的$l",
        "force": 20,
        "dodge": 30,
        "damage_type": "瘀傷"
    ]),
    ([
        "action": "$N移身挪步，一式「掖底偷桃」，單拳向$n的$l打去",
        "force": 30,
        "dodge": 30,
        "damage_type": "瘀傷"
    ]),
    ([
        "action": "$N將全身內力聚在手掌之上，雙掌慢慢飄向$n的$l",
        "force": 40,
        "dodge": 40,
        "damage_type": "瘀傷"
    ]),
    ([
        "action": "$N身子平平向前，單手飛向$n的$l",
        "force": 50,
        "dodge": 50,
        "damage_type": "瘀傷"
    ]),

});

int valid_learn(object me) {
    return 1;
}

int valid_enable(string usage) {
    return (usage=="unarmed") || (usage=="throwing");
}

mapping query_action(object me, object weapon) {
    return action[random(sizeof(action))];
}

int practice_skill(object me) {
    if((int)me->query("kee") < 30 )
        return notify_fail("你的體力不夠了，休息一下再練吧。\n");
    me->receive_damage("kee", 30, "tire");
    return 1;
}

int effective_level() { return 11;}

string *parry_msg = ({
    "$n雙手一引，$N手中的$w略偏了一分，從$n的身旁飛了過去。\n"
});
string *unarmed_parry_msg = ({
    "$n一招「靈蛇出洞」，輕巧的擋開了$N的招式。\n"
});

varargs string query_parry_msg(object me, object weapon) {
    if(weapon )
        return parry_msg[random(sizeof(parry_msg))];
    else
        return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
int learn_bonus() {
    return 0;
}
int practice_bonus() {
    return 0;
}
int black_white_ness() {
    return 0;
}

string perform_action_file(string action) {
    return __DIR__ + "/wuying-zhang/" + action;
}
