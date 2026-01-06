// tianlong-xiang.c 天龍翔
//COOL@SJ
inherit SKILL;

string *dodge_msg = ({
    "$n雙掌連拍，身子忽屈忽伸，猶如蛟龍飛舞，人借掌勢，風吹人衫，身體突然騰上半空，劃出一道曲線，遠遠的飄了開去。\n",
    "$n腳下猛力一登，騰空躍起，凌空一大步就跨過$N的上方，穩穩的落在$N的後面，$N禁不住喝了個彩：好一招「凌虛渡」。\n",
    "但見$n身在半空，長吐一口氣，”譁、譁、譁“，雙袖連揮數下，使一招「龍翱九天」，身形不見下墜，反而越飄越高。\n",
    "$N突然一招擊出，$n見躲避不過，一掌擊出，藉著$N的勁道，連翻幾個筋斗，遠遠的躲了開去。\n",
    "$n雙腿輪番踢出，身體順勢連續翻滾，一式「神龍降世」，跳出了$N的攻擊範圍。\n",
    "$n一招「龍游四海」，身子一彎一扭，貼著地面平平滑開,$N眼前人影一晃，失去了$n的蹤影。\n",
    "$n長嘯一聲，使一招「神龍飛昇」，騰空而起，一陣狂風吹來，$n雙袖鼓起，盤旋揮舞，藉著那一陣風勢，越舞越高。\n",
    "$n迅速解下衣衫，迎風一展，身子踏空而起，在風中飄飄然然而行，正是那招「龍行天下」。\n"
});

int valid_enable(string usage) {
    return usage == "dodge";
}

int valid_learn(object me) {
    if (!me->query_skill("kurong-changong", 1))
        if (me->query_skill("qiantian-yiyang", 1) < 10)
        return notify_fail("你的乾天一陽功等級太低了。\n");
    return 1;
}

string query_dodge_msg(string limb) {
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me) {
    if((int)me->query("jingli") < 30 )
        return notify_fail("你的體力太差了，不能練習天龍翔。\n");
    me->receive_damage("jingli", 25);
    return 1;
}
