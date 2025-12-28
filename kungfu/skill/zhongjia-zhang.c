// zhongjia-zhang.c 鍾家掌法
// NPC 專用

inherit SKILL;

mapping *action = ({
([     "action" : "$N縱身向前，掌勢一發即收，雙掌連晃，二掌直出，攻向$n的上中下三路",
       "force" : 150,
        "dodge" : 5,
       "damage_type" : "瘀傷",
       "lvl" : 0,
]),
([     "action" : "$N躍起丈餘，在半空連轉兩個圈子，凌空揮掌，疾拍$n的胸前大穴",
       "force" : 160,
        "dodge" : 5,
        "damage_type" : "瘀傷",
       "lvl" : 12,
]),
([     "action" : "$N單臂畫了個弧線，劈頭蓋臉地斬向$n的$l",
       "force" : 170,
        "dodge" : 5,
        "damage_type" : "劈傷",
       "lvl" : 18,
]),
([     "action" : "$N左掌護胸，立掌如劍，單手橫劈，颼颼風響，猛地推向$n的$l",
       "force" : 185,
        "dodge" : -5,
        "damage_type" : "瘀傷",
       "lvl" : 24,
])
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
       if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
               return notify_fail("練鍾家掌法必須空手。\n");
       if ((int)me->query_skill("jinglei-gong", 1) < 20)
               return notify_fail("你的驚雷功火候不夠，無法學鍾家掌法。\n");
       if ((int)me->query("max_neili") < 100)
               return notify_fail("你的內力太弱，無法練鍾家掌法。\n");
       return 1;
}

string query_skill_name(int level)
{
       int i;
       for(i = sizeof(action)-1; i >= 0; i--)
               if(level >= action[i]["lvl"])
                       return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
       int i, level;
       level = (int)me->query_skill("zhongjia-zhang", 1);
       for(i = sizeof(action); i > 0; i--)
               if(level > action[i-1]["lvl"])
                       return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
       if ((int)me->query("jingli") < 30)
               return notify_fail("你的精力太低了。\n");
       if ((int)me->query("neili") < 20)
               return notify_fail("你的內力不夠練鍾家掌法。\n");
       me->receive_damage("jingli", 25);
       me->add("neili", -5);
       return 1;
}
