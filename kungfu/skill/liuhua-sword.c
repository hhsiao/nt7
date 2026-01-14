// liuhua-sword.c
// 流花掠影劍

inherit SKILL;

mapping *action = ({
([      "action":"$N的$w斜斜的升出，一招「不緊不慢」刺向$n的$l",
        "dodge" : -10,
        "damage": 45,
        "damage_type":  "刺傷"
]),
([      "action":"$N手中的$w一閃，一式「你情我願」罩向$n的$l",
        "dodge" : -10,
        "damage": 60,
        "damage_type":  "割傷"
]),
([      "action":"$N身形一閃，從$n的視線裡消失，$w卻飛向$n的$l",
        "dodge" : 45,
        "damage": 130,
        "damage_type":  "割傷"
]),
([      "action":"$N一個轉身，$w在身邊一閃一閃，剎那間斬向$n的$l",
        "dodge" : 10,
        "damage": 55,
        "damage_type":  "割傷"
]),
([      "action":"$N手中$w中宮直進，無聲無息地對準$n的$l刺出一劍",
        "dodge" : 35,
        "damage": 160,
        "damage_type":  "刺傷"
]),
([      "action":"$N手中的$w發出丈許劍芒，內力從劍削髮出，直逼$n的$l而去",
        "dodge" : 60,
        "damage": 155,
        "damage_type":  "刺傷"
]),
([      "action":"$N雙手握緊$w，劍鋒透出寒氣，看似極平凡的一招向$n的$l逼去",
        "dodge" : 70,
        "damage": 180,
        "damage_type":  "割傷"
]),

});

int valid_learn(object me)
{
	object ob;

	if( !(ob = me->query_temp("weapon"))
	|| (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必須先找一把劍才能練劍法。\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 || (int)me->query("force") < 3 )
		return notify_fail("你的內力或氣不夠，沒有辦法練習流花掠影劍。\n");
	me->receive_damage("kee", 30, "tire");
	me->add("force", -3);
	write("你按著所學練了一遍流花掠影劍。\n");
	return 1;
}

int effective_level() { return 11;}

int learn_bonus()
{
	return -10;
}

int practice_bonus()
{
	return -10;
}

int black_white_ness()
{
	return -10;
}

string *parry_msg = ({
	"$v從$n手中閃出格開了$N的$w。\n",
});

string *unarmed_parry_msg = ({
	"$n手中的$v形成了一道網，死死的封住了$N的攻勢。\n",
});

varargs string query_parry_msg(object me, object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string perform_action_file(string action)
{
	return __DIR__ + "/liuhua-sword/" + action;
}
