// 天涯明月刀 written by tiandi。
/*
 * 傅紅雪已拔刀。
 * 天下無雙的刀，不可思儀的刀法。
 * 無論多惡毒的暗器，無論多複雜的詭計，遇見了這把刀，就像是冰雪到了陽光下。
 * 刀光閃，一連串金鈴般的輕響，滿天暗器落地，每一件暗器都被削斷了，都是從正中間斷的，就算巧手匠人用小刀一件件停細分割也未必能如此精確。
 * 刀光消失後，才看見血，血是從臉上流下的
 * 屠青的臉。
 * 一道刀口從他眉毛間刻下來，劃過鼻尖，這一刀只要多用三分力，他的頭
 * 刀已人鞘。
 * 鮮血從鼻尖流落，流入嘴唇，又熱又鹹又苦。屠青臉上每一根肌肉都已因痛苦而抽搐他的人卻沒有動
 */
inherit SKILL;

mapping *action = ({
    ([      "action":
        "就在這時，$N飄飛倏忽的，呼地斗然翻出，縱刀斜削，金刀耀日，一剎那間，下了七記殺手",
        "dodge": -120,
        "damage": 230,
        "damage_type": "割傷"
    ]),
    ([      "action":
        "就在這時忽然有刀光一閃，這就是$N的$w，天上地下，獨一無二的刀",
        "dodge": -120,
        "damage": 330,
        "damage_type": "割傷"
    ]),
    ([      "action":
        "就在這刻不容緩的一瞬問，$N的$w突然自肋下穿出，“叮”的一響，$w迸出火花，激向$n的$l處",
        "dodge": -130,
        "damage": 220,
        "damage_type": "割傷"
    ]),
    ([      "action":
        "刀光又一斬，屋簷破裂。$w的威力，如雷霆霹靂，橫刀再斬$n，眨眼間已斬下了七刀",
        "dodge": -140,
        "damage_type": "割傷"
    ]),
    ([      "action":
        "驟然間，一片刀光，一道血影，左右直撲$n！\n這一下變生時腋，刀光凌厲，而且絕，除了一刀致命的人體部位外，別的地方都不打",
        "dodge": -240,
        "damage_type": "割傷"
    ]),

});

int valid_learn(object me) {
    object ob;
    if (me->query("gender") != "男性")
        return notify_fail("你好象不是男的吧。\n");
    if(me->query("TASK") < 1000  || !me->query("marks/kuaihuo") )
        return notify_fail("以你目前的狀況，還沒有資格練此功夫。\n");
    if ((int)me->query_skill("moshen-force", 1) < 50)
        return notify_fail("你的魔神訣不夠。\n");

    if((int)me->query("max_force") < 200 )
        return notify_fail("你的內力不夠，沒有辦法練天涯明月刀。\n");

    if(!(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade" )
        return notify_fail("刀呢？\n");

    return 1;
}

int valid_enable(string usage) {
    return usage=="blade" || usage=="parry";
}

mapping query_action(object me, object weapon) {
    return action[random(sizeof(action))];
}

int practice_skill(object me) {
    if((int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
        return
    notify_fail("你的內力或氣不夠，沒有辦法練習天涯明月刀。\n");
    me->receive_damage("kee", 30);
    me->add("force", -3);
    write("你按著所學練了一遍天涯明月刀。\n");
    return 1;
}

string perform_action_file(string action) {
    return CLASS_D("moon") + "/tianya-blade/" + action;
}

int effective_level() { return 35;}

string *parry_msg = ({
    "$n沒有閃避，沒有動，動的是$n的刀，“盯”的一響，火星四激，一道刀光沖天面起，看來就像是已種破雲層飛至天外。\n",
    "$n的身子忽然斜斜飛出，恰巧從邊緣掠過。\n"
});

string *unarmed_parry_msg = ({
    "$n沒有閃避，沒有動，動的是$n的刀，“盯”的一響，火星四激，一道刀光沖天面起，看來就像是已種破雲層飛至天外。\n",
    "$n的身子忽然斜斜飛出，恰巧從邊緣掠過。\n"
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
    return -30;
}
int black_white_ness() {
    return 15;
}
