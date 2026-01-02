inherit SKILL;
string *dodge_msg = ({
    "$n一招“月堤徘徊”，漫不經心的向左邁出一步，剛好避過$N的凌厲攻勢。\n",
    "$n使一招“冷月清風”，身體向上筆直地縱起丈餘，躲過了$N這一招。\n",
    "$n施展“明月春潮”,向一旁飄然縱出，輕輕著地。\n",
    "$n身形微晃，一招“殘月蟬聲”，有驚無險地避開了$N這一招。\n",
    "$n使出“寒月霜天”，身形化實為虛地躲開了$N這一招。\n"
});

int valid_enable(string usage) {
    return (usage=="dodge");
}

int valid_learn(object me) {
    return 1;
}

string query_dodge_msg(string limb) {
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me) {
    if((int)me->query("kee") < 30 )
        return notify_fail("你的體力太差了，不能練圓月步法。\n");
    me->receive_damage("kee", 30);
    return 1;
}
int effective_level() { return 20;}

int learn_bonus() {
    return 0;
}
int practice_bonus() {
    return 3;
}
int black_white_ness() {
    return 0;
}

string perform_action_file(string action) {
    return CLASS_D("moon") + "/moon-steps/" + action;
}
