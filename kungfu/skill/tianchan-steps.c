// tianchan-steps.c
// by Find.
// 天蟬步法

inherit SKILL;

string *dodge_msg = ({
    "$n雙足輕輕點地，身形若隱若現，$N的招式完全落空。\n",
    "$n一式「風裡避風」，瞬間人已不見了蹤影。\n",
    "$n雙足一蹬，人以落在了丈許開外，$N的招式對$n絲毫無損。\n",
    "只見$n腰身東躲西閃，$N的招法盡數落空。\n"
});

int valid_enable(string usage) {
    return (usage == "dodge");
}

string perform_action_file(string action) {
    return CLASS_D("tangmen") + "/tianchan-steps/" + action;
}

int valid_learn(object me) { return 1; }

varargs query_dodge_msg(object me, string limb) {
    return dodge_msg[random(sizeof(dodge_msg))];
}

int effective_level() { return 12;}

int practice_skill(object me) {
    if((int)me->query("kee") < 40 )
        return notify_fail("你的體力太差了，不能練習天蟬步法。\n");
    me->receive_damage("kee", 30, "tire");
    return 1;
}

/* 此函數返回值越小越難練，越大越好練，0 為正常難度。*/
int practice_bonus() {
    return -10;
}


/* 此函數返回值越小越難學，越大越好學，0 為正常難度。*/
int learn_bonus() {
    return -10;
}

/*
 * 當這項武功小於 75 級時，此函數返回值越小學的越快。
 * 當這項武功大於 75 級時，此函數返回值越大學的越快。
 * 當這項武功等於 75 級時，此函數返回值沒有意義。
 * 也就是說此函數返回值小，利於初期學習，但越學越難
 * 函數返回值大，初期學習很難，但越學越快
 * 函數返回值為零正常，前後階段難度沒有變化
 */
int black_white_ness() {
    return 0;
}
