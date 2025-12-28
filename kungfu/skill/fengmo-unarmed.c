// This is player's own skill (Write by Lonely@nt2)
// Create by 周不通(Butong) at Thu May 28 17:23:54 2015
// 瘋魔拳(fengmo-unarmed.c)

#include <ansi.h>
inherit SKILL;        
                
int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
([      "action" : "$N看上去半瘋不癲，一臉傻笑，腳步不穩，卻忽然一式「仙人摘桃」，自下而上往$n襠下一抓。",
	"attack" : 260,
	"damage" : 260,
	"force" : 260,
	"dodge" : 260,
	"parry" : 260,
	"lvl" : 100,
	"damage_type" : "瘀傷",
	"skill_name" : "半瘋不癲"
 ]),
// ZHAOSHI : 1
});

int valid_learn(object me)
{
        if( query_temp("weapon", me) || query_temp("secondary_weapon", me) )
                return notify_fail("練"+"瘋魔拳"+"必須空手。\n");
        if( query("max_neili", me)<50 )
                return notify_fail("你的內力太弱，無法練"+"瘋魔拳"+"。\n");
        return 1;
}

int valid_enable(string usage) { 
        return usage == "unarmed" || 
               usage == "parry"; 
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
        level = (int)me->query_skill("fengmo-unarmed",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

mixed *query_actions() { return action; }

int query_effect_parry(object attacker, object me)
{
        int lvl;

        if( query_temp("weapon", me) )
                return 0;

        lvl = me->query_skill("fengmo-unarmed", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}

int practice_skill(object me)
{
        if( query("qi", me)<25 )
                return notify_fail("你的體力不夠了，休息一下再練吧。\n");
        if( query("neili", me)<3 )
                return notify_fail("你的內力不夠了，休息一下再練吧。\n");
        me->receive_damage("qi", 25);
        addn("neili", -3, me);
        return 1;
} 

mixed hit_ob(object me, object victim, int damage)
{
        mixed result;
        if (damage < 100) return 0;

        if (random(damage) > victim->query_str()) 
        {
                result = ([ "damage" : damage ]);
                result += ([ "msg" : HIW "你聽到「喀嚓」一聲輕響，已被$N所發殺氣挫傷，$n頓時血冒三丈！！！\n" NOR ]);

                return result;
        }
}

string perform_action_file(string action) 
{
        return __DIR__ + "fengmo-unarmed" + "/" + action; 
}
string query_description()
{
	return
 "這套瘋魔拳法，乃是全真教高人周不通瘋狂時所創，招式威猛無比，快比
迅雷，拳如流星，一旦發狂以後千人也難以匹敵，萬夫莫當。當年周不通
以這套瘋魔拳打高處不勝寒，掌劈紅蓮老祖。連網遊始祖也被一拳打倒在
泥潭。" ; 
}
