// This is player's own skill (Write by Lonely@nt2)
// Create by 星雲鎖鏈(Fuyuan) at Tue Mar  3 00:40:31 2015
// 野球拳(yeqiu-unarmed.c)

#include <ansi.h>
inherit SKILL;        
                
int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
([      "action" : "$N俯首沉腰，身形一閃，躍到$n身後，一式「老漢推車」，兩手死死的揪住$n的腳脖子，然後用力向上一提，往前一抖扔進前面的臭水溝裡。",
	"attack" : 260,
	"damage" : 260,
	"force" : 260,
	"dodge" : 260,
	"parry" : 260,
	"lvl" : 100,
	"damage_type" : "瘀傷",
	"skill_name" : "老漢推車"
 ]),
// ZHAOSHI : 1
([      "action" : "$N飛身躍起，空中一個盤旋，一式「枯樹盤根」，雙腿死死鎖住$n的脖子，然後用力一扭……",
	"attack" : 260,
	"damage" : 260,
	"force" : 260,
	"dodge" : 260,
	"parry" : 260,
	"lvl" : 110,
	"damage_type" : "瘀傷",
	"skill_name" : "枯樹盤根"
 ]),
// ZHAOSHI : 2
([      "action" : "$N嘎嘎怪笑，團身鑽入$n襠下，口中喝到，看我「雞飛蛋打」，揮拳狠狠向上搗去。",
	"attack" : 260,
	"damage" : 260,
	"force" : 260,
	"dodge" : 260,
	"parry" : 260,
	"lvl" : 120,
	"damage_type" : "瘀傷",
	"skill_name" : "雞飛蛋打"
 ]),
// ZHAOSHI : 3
([      "action" : "$N縱身一個空翻，從$n頭頂躍過，落地時順勢在$n屁股蛋子上狠狠踹了一腳，$n一個標準的「平沙落雁」姿勢摔了個馬趴。",
	"attack" : 260,
	"damage" : 260,
	"force" : 260,
	"dodge" : 260,
	"parry" : 260,
	"lvl" : 130,
	"damage_type" : "瘀傷",
	"skill_name" : "平沙落雁"
 ]),
// ZHAOSHI : 4
([      "action" : "$N噼啦噼啦對著自己的屁股一頓猛捶，$n微一愣神，被$N近身伸出食指一式「姜太公釣魚」穿進鼻孔，頓時鼻血噴湧而出。",
	"attack" : 260,
	"damage" : 260,
	"force" : 260,
	"dodge" : 260,
	"parry" : 260,
	"lvl" : 140,
	"damage_type" : "瘀傷",
	"skill_name" : "姜太公釣魚"
 ]),
// ZHAOSHI : 5
([      "action" : "$N念念叨叨，作「小和尚唸經」狀，左手虛握胸前防禦，右手抽風般只把$n的腦門當做木魚死命猛敲。",
	"attack" : 260,
	"damage" : 260,
	"force" : 260,
	"dodge" : 260,
	"parry" : 260,
	"lvl" : 150,
	"damage_type" : "瘀傷",
	"skill_name" : "小和尚唸經"
 ]),
// ZHAOSHI : 6
([      "action" : "$n俯身向$N的下三路發起進攻，$N魚躍閃過，順勢一式「烏雲蓋頂」，屁股狠狠的坐在$n頭上。",
	"attack" : 260,
	"damage" : 260,
	"force" : 260,
	"dodge" : 260,
	"parry" : 260,
	"lvl" : 160,
	"damage_type" : "瘀傷",
	"skill_name" : "烏雲蓋頂"
 ]),
// ZHAOSHI : 7
([      "action" : "$N突然雙腳靜止不動，上身大幅旋轉，$n一不留神立馬中招，暈乎乎被這招「大風車」旋飛出去。",
	"attack" : 260,
	"damage" : 260,
	"force" : 260,
	"dodge" : 260,
	"parry" : 260,
	"lvl" : 180,
	"damage_type" : "瘀傷",
	"skill_name" : "大風車"
 ]),
// ZHAOSHI : 8
([      "action" : "$N氣貫頭頂，對$n的進攻不管不顧，一式「老和尚撞鐘」，直往$n的胸口撞去。",
	"attack" : 260,
	"damage" : 260,
	"force" : 260,
	"dodge" : 260,
	"parry" : 260,
	"lvl" : 200,
	"damage_type" : "瘀傷",
	"skill_name" : "老和尚撞鐘"
 ]),
// ZHAOSHI : 9
});

int valid_learn(object me)
{
        if( query_temp("weapon", me) || query_temp("secondary_weapon", me) )
                return notify_fail("練"+"野球拳"+"必須空手。\n");
        if( query("max_neili", me)<50 )
                return notify_fail("你的內力太弱，無法練"+"野球拳"+"。\n");
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
        level = (int)me->query_skill("yeqiu-unarmed",1);
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

        lvl = me->query_skill("yeqiu-unarmed", 1);
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
        return __DIR__ + "yeqiu-unarmed" + "/" + action; 
}