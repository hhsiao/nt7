// This is player's own skill (Write by Lonely@nt2)
// Create by 了盡(Zxahh) at Thu Feb 26 21:57:20 2015
// 隨意掌(suiyi-strike.c)

#include <ansi.h>
inherit SKILL;        
                
int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
([      "action" : "$N突然如同放棄了所有武學招式隨意而動，腳步悠然一如踏青而行，卻瞬間出現在$n面前，$n還沒反應過來，便被一巴掌摔倒了臉上！",
	"attack" : 260,
	"damage" : 260,
	"force" : 260,
	"dodge" : 260,
	"parry" : 260,
	"lvl" : 100,
	"damage_type" : "內傷",
	"skill_name" : "隨意而為"
 ]),
// ZHAOSHI : 1
([      "action" : "$N忽如消失一般，$n定神一看，不知何時$N已經出現在身後，無論如何也無法逃脫，$n驚恐之下被$N一掌拍中了後腦勺",
	"attack" : 260,
	"damage" : 260,
	"force" : 260,
	"dodge" : 260,
	"parry" : 260,
	"lvl" : 110,
	"damage_type" : "內傷",
	"skill_name" : "如影相隨"
 ]),
// ZHAOSHI : 2
([      "action" : "$N暮然回身背對這$n，讓$n不由一愣，咋時$N一個進步後跨，後肘擊中了$n的胸口！",
	"attack" : 260,
	"damage" : 260,
	"force" : 260,
	"dodge" : 260,
	"parry" : 260,
	"lvl" : 120,
	"damage_type" : "內傷",
	"skill_name" : "意想不到"
 ]),
// ZHAOSHI : 3
([      "action" : "$N靈機一發，身體已經一步跨到了$n的面前，一掌拍向了$n的天靈蓋",
	"attack" : 260,
	"damage" : 260,
	"force" : 260,
	"dodge" : 260,
	"parry" : 260,
	"lvl" : 130,
	"damage_type" : "內傷",
	"skill_name" : "身隨意動"
 ]),
// ZHAOSHI : 4
([      "action" : "$N兩臂如鵬翼般揮動，一股強大的內力猶如颶風拍在了$n的胸口，是$n的內府具碎！",
	"attack" : 260,
	"damage" : 260,
	"force" : 260,
	"dodge" : 260,
	"parry" : 260,
	"lvl" : 140,
	"damage_type" : "內傷",
	"skill_name" : "一切隨風"
 ]),
// ZHAOSHI : 5
([      "action" : "$N怒喝一聲，$n只覺一聲驚雷在腦中響起，還沒回過神來，$N已經伴隨喝聲出現在$n面前，一掌拍在了$n心脈之上！",
	"attack" : 260,
	"damage" : 260,
	"force" : 260,
	"dodge" : 260,
	"parry" : 260,
	"lvl" : 150,
	"damage_type" : "內傷",
	"skill_name" : "言出法隨"
 ]),
// ZHAOSHI : 6
([      "action" : "$n看到$N露出了破綻正欲進攻，$N突然一個扭動破綻居然消失無蹤，一招殺招出現其中！",
	"attack" : 260,
	"damage" : 260,
	"force" : 260,
	"dodge" : 260,
	"parry" : 260,
	"lvl" : 160,
	"damage_type" : "內傷",
	"skill_name" : "出其不意"
 ]),
// ZHAOSHI : 7
([      "action" : "$N一躍而起，一掌上而下推出，巨大的掌壓若天意般壓下",
	"attack" : 260,
	"damage" : 260,
	"force" : 260,
	"dodge" : 260,
	"parry" : 260,
	"lvl" : 180,
	"damage_type" : "內傷",
	"skill_name" : "一意動天"
 ]),
// ZHAOSHI : 8
([      "action" : "$N繞著$n轉了一圈，$n沒感覺有任何異樣，突然之間感覺身體內一陣波動，確實幾十重內勁同時爆發了！",
	"attack" : 260,
	"damage" : 260,
	"force" : 260,
	"dodge" : 260,
	"parry" : 260,
	"lvl" : 200,
	"damage_type" : "內傷",
	"skill_name" : "逍遙隨意"
 ]),
// ZHAOSHI : 9
});

int valid_learn(object me)
{
        if( query_temp("weapon", me) || query_temp("secondary_weapon", me) )
                return notify_fail("練"+"隨意掌"+"必須空手。\n");
        if( query("max_neili", me)<50 )
                return notify_fail("你的內力太弱，無法練"+"隨意掌"+"。\n");
        return 1;
}

int valid_enable(string usage) { 
        return usage == "strike" || 
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
        level = (int)me->query_skill("suiyi-strike",1);
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

        lvl = me->query_skill("suiyi-strike", 1);
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
        return __DIR__ + "suiyi-strike" + "/" + action; 
}