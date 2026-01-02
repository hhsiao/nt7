inherit SKILL;
mapping *action = ({
    ([      "action": "$N神功默運，使出“暮雲收盡溢清寒”，手中的$w急斬$n的$l",
        "damage": 80,
        "dodge": 200,
        "parry": 100,
        "damage_type": "割傷"
    ]),
    ([      "action": "$N手中的$w，突然一招“銀漢無聲轉玉盤”化為漫天刀光，卷向$n的$l",
        "damage": 70,
        "dodge": 150,
        "parry": 150,
        "damage_type": "割傷"
    ]),
    ([      "action": "$N刀鋒忽轉，手中的$w使出神刀斬裡的“月光如水水如天”，閃電般劈向$n的$l",
        "damage": 90,
        "dodge": 200,
        "parry": 100,
        "damage_type": "割傷"
    ]),
    ([      "action": "$N身影晃動，刀式飄忽，一招“梨花清影溶溶月”，手中的$w，急襲$n的$l",
        "damage": 50,
        "dodge": 200,
        "parry": 200,
        "damage_type": "割傷"
    ]),
    ([      "action": "$N刀鋒向外，去勢如風，手中的$w，一氣呵成橫掃$n的$l",
        "damage": 100,
        "dodge": 200,
        "parry": 100,
        "damage_type": "割傷"
    ])
});

int valid_learn(object me) {
    if((int)me->query_skill("force", 1) < 200 )
        return
    notify_fail("你的內功心法火候不足，無法習練圓月神刀斬。\n");
    if((int)me->query_skill("blade", 1) < 200 )
        return
    notify_fail("你的基本刀法火候不足，無法習練圓月神刀斬。\n");
    if(me->query("class")!="bandit" )
        return
    notify_fail("你無法領悟圓月神刀斬的真義。\n");
    return 1;
}

int valid_enable(string usage) {
    return (usage=="blade") || (usage=="parry");
}

mapping query_action(object me, object weapon) {
    return action[random(sizeof(action))];
}

int practice_skill(object me) {
    object weapon;

    if(!objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "blade" )
        return notify_fail("你必須先找一把刀，才能練刀法。\n");

    if((int)me->query("kee") < 40 )
        return notify_fail("你的體力不夠練這門刀法，還是先休息休息吧。\n");
    me->receive_damage("kee", 40);
    return 1;
}
int effective_level() { return 40;}

string *parry_msg = ({
    "$n使一招“寒刀月影”，手中的$v化成一片刀影護住全身要害。\n"
});

string *unarmed_parry_msg = ({
    "$n使出“神女奔月”，$v化成漫天刀光，將攻勢化解於無形。\n"
});

string query_parry_msg(object weapon) {
    if(weapon )
        return parry_msg[random(sizeof(parry_msg))];
    else
        return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus() {
    return 0;
}
int practice_bonus() {
    return 5;
}
int black_white_ness() {
    return 20;
}

string perform_action_file(string action) {
    return CLASS_D("moon") + "/moon-blade/" + action;
}
