// This is player's own skill (Write by Lonely@nt2)
// Create by 渡歐(Ssyunone) at Sun Mar  8 19:13:00 2015
// 無色無相神劍(wusewx-sword.c)

#include <ansi.h>
inherit SKILL;        
                
int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
([      "action" : "HIW$NHIW一招擊在$nHIW身上，卻被$nHIW暗運易筋經內功，將內力盡數移入地下。\nNOR,HIW$n輕輕一帶，$NHIW發現自己招數回擊過來，嚇得往後倒退幾步。\nNOR,HIW$n手臂迴轉，在$NHIW手肘下輕輕一推，$NHIW招數落空。\nNOR,HIW$n右手伸出，在$NHIW手腕上輕輕一拉，$NHIW收勢不住，直往前撲去。\nNOR,HIW$n身形不動，$NHIW一招擊下，有如石沉大海，不覺呆住了。\nNOR,HIW$n左牽右引，$NHIW如身處漩流，連續轉了好幾個圈。\nNOR,HIW$n雙手迴圈，$NHIW只覺得前面好象有一堵牆，再也攻不進去。\nNOR,HIW$n輕輕一轉，$NHIW一招擊在地上，只打得塵土飛揚。\nNOR。",
	"attack" : 260,
	"damage" : 260,
	"force" : 260,
	"dodge" : 260,
	"parry" : 260,
	"lvl" : 100,
	"damage_type" : "刺傷",
	"skill_name" : "降妖伏魔"
 ]),
// ZHAOSHI : 1
});

int valid_learn(object me)
{
        object weapon; 
        
        if( !objectp(weapon=query_temp("weapon", me) )
                 || query("skill_type", weapon) != "sword" )
                return notify_fail("你使用的武器不對。\n");
                
        if( query("max_neili", me)<50 )
                return notify_fail("你的內力太弱，無法練" + "無色無相神劍" + "。\n");
                
        return 1;
}

int valid_enable(string usage) { 
        return usage == "sword" || 
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
        level = (int)me->query_skill("wusewx-sword",1);
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

        lvl = me->query_skill("wusewx-sword", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}

int practice_skill(object me)
{
        object weapon; 
        if( !objectp(weapon=query_temp("weapon", me)) || 
                query("skill_type", weapon) != "sword" )
                return notify_fail("你使用的武器不對。\n");        
        
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
                result += ([ "msg" : HIW "你聽到「喀嚓」一聲輕響，已被$N的兵器所發殺氣挫傷，$n頓時血冒三丈！！！\n" NOR ]);

                return result;
        }
}

string perform_action_file(string action) 
{
        return __DIR__ + "wusewx-sword" + "/" + action; 
}
string query_description()
{
	return
 "無色無相神劍是創自渡歐的絕世劍法，招式勇往直前，大開大闔，以勇猛
霸道而著稱，當初江湖十大掌門圍攻渡歐的時候，情勢萬分危機，渡歐在
千鈞一髮之際使出這套武功，頓時風雲變色，化險為夷…該劍法大舟小舟
無不載，大魚小魚無不容，是劍法和禪宗心法的極致結晶… '.'" ; 
}
