#include <ansi.h>
inherit SKILL;

mapping *action = ({
    ([
        "action": "$N翻腕一振$w，一招「"+HIY"獅子搖頭"NOR + "」，槍上紅纓抖動，挽出斗大一個槍花，往$n$l直搠過去",
        "lvl": 0,
        "skill_name": "獅子搖頭",
        "damage_type": "刺傷"
    ]),
    ([
        "action": "$N倒轉$w，一招「"+HIY"白虹經天"NOR + "」，斜身移睬宮槍桿起處，圓圓一團紅影，槍尖上一點寒光疾向$n刺來",
        "lvl": 30,
        "skill_name": "白虹經天",
        "damage_type": "割傷"
    ]),
    ([
        "action": "$N催動身法急走如飛，手中$w一抖，使出一招「"+HIY"朝天一柱香"NOR + "」，$w挺得筆直，迅捷無倫地刺向$n的$l",
        "lvl": 60,
        "skill_name": "朝天一柱香",
        "damage_type": "割傷"
    ]),
    ([
        "action": "$N挺起$w，一招「"+HIY"鳳點頭"NOR + "」，紅纓抖動，$w幻出點點槍影，槍尖閃爍不定地往$n$l點到",
        "lvl": 90,
        "skill_name": "鳳點頭",
        "damage_type": "刺傷"
    ]),
    ([
        "action": "$N一招「"+HIY"春雷震怒"NOR + "」，刷刷刷連環三槍，急刺而至，朱纓亂擺，$w嗤嗤聲響，顫成一個大紅圈子，罩住了$n上下各路",
        "lvl": 120,
        "skill_name": "春雷震怒",
        "damage_type": "割傷"
    ]),
    ([
        "action": "$N突然大喝一聲，雙手抓住槍柄，勁力到處$w彎成弓形，突然一鬆手，電光一閃劈空刺向$n，好一招「"+HIY"靈蛇電閃"NOR + "」",
        "lvl": 150,
        "skill_name": "靈蛇電閃",
        "damage_type": "刺傷"
    ]),
    ([
        "action": "$N突然踏上一睬宮$w挺得筆直，使出一招「"+HIY"孤雁出群"NOR + "」，$w來勢如風，凌厲無匹地向$n的$l刺去",
        "lvl": 180,
        "skill_name": "孤雁出群",
        "damage_type": "刺傷"
    ])
});

int valid_enable(string usage) {
    if (query("quest/射鵰英雄傳/yangjiaqiang/pass", this_player()))
        return usage == "spear" || usage == "parry";
}

int valid_learn(object me) {
    if(me->query_skill("yangjia-qiang", 1) < 1 )
        return notify_fail("楊家槍只能從楊鐵心處習到。\n");
    return 1;
}

string query_skill_name(int level) {
    int i;
    for(i = sizeof(action) - 1; i >= 0; i--)
        if(level >= action[i]["lvl"])
        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon) {
    int i, j, level, lv2;
    level = me->query_skill("yangjia-qiang", 1);
    lv2 = me->query_skill("spear", 1) / 2;

    for(i = sizeof(action); i > 0; i--){
        if(level > action[i - 1]["lvl"]){
            j = NewRandom(i, 20, level / 5);

            if(query_temp("yjq/huima", me)){
                return ([
                    "action": HIC + replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIC), NOR, HIC) + NOR,
                    "lvl": action[j]["lvl"],
                    "force": 120 + random(250) + lv2 / 10,
                    "dodge": random(20)- 5 + lv2 / 15,
                    "damage": 60 + random(80) + random((level + lv2) / 4),
                    "parry": random(15) + lv2 / 10,
                    "weapon": random(2)?"槍氣":"槍鋒",
                    "damage_type": random(2)?"刺傷":"割傷"
                    ]);
            }
            if(query_temp("yjq/jifeng", me)){
                return ([
                    "action": MAG + replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"MAG), NOR, MAG) + NOR,
                    "lvl": action[j]["lvl"],
                    "force": 120 + random(250) + lv2 / 10,
                    "dodge": random(20)- 5 + lv2 / 15,
                    "damage": 70 + random(100) + random((level + lv2) / 4),
                    "parry": random(15) + lv2 / 10,
                    "weapon": random(2)?"槍氣":"槍鋒",
                    "damage_type": random(2)?"刺傷":"割傷"
                    ]);
            }
            if(query_temp("yjq/qinghe", me)){
                return ([
                    "action": HIG + replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIG), NOR, HIG) + NOR,
                    "lvl": action[j]["lvl"],
                    "force": 120 + random(250) + lv2 / 10,
                    "dodge": random(20)- 5 + lv2 / 15,
                    "damage": 80 + random(100) + random((level + lv2) / 5),
                    "parry": random(15) + lv2 / 10,
                    "weapon": random(2)?"槍氣":"槍鋒",
                    "damage_type": random(2)?"刺傷":"割傷"
                    ]);
            }
            if(query_temp("yjq/shenwei", me)){
                return ([
                    "action": HIR + replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIR), NOR, HIR) + NOR,
                    "lvl": action[j]["lvl"],
                    "force": 120 + random(250) + lv2 / 10,
                    "dodge": random(20)- 5 + lv2 / 15,
                    "damage": 80 + random(100) + random((level + lv2) / 5),
                    "parry": random(15) + lv2 / 10,
                    "weapon": random(2)?"槍氣":"槍鋒",
                    "damage_type": random(2)?"刺傷":"割傷"
                    ]);
            }
            return ([
                "action": action[j]["action"],
                "force": 100 + random(250),
                "dodge": random(20) - 10,
                "parry": random(10),
                "damage": 80 + random(80),
                "lvl": action[j]["lvl"],
                "damage_type": action[j]["damage_type"]
                ]);
        }
    }
}

int practice_skill(object me) {
    object weapon;

    if(!objectp(weapon = query_temp("weapon", me) )
        || query("skill_type", weapon) != "spear" )
        return notify_fail("你使用的武器不對。\n");
    if(query("jingli", me)<50 )
        return notify_fail("你的體力不夠練楊家槍。\n");
    me->receive_damage("jingli", 20);
    return 1;
}

string perform_action_file(string action) {
    return __DIR__"yangjia-qiang/" + action;
}

mixed hit_ob(object me, object target, int damage_bonus) {
    int lv = me->query_skill("yangjia-qiang");

    if(random(5)>3 && lv>250 && !query_temp("yjq/hmq", me) )
    {
        message_vision(YEL"$N大喝一聲，雙手抓住槍柄，斗然間擰腰縱臂，回身出槍，直刺$n面門，這一槍正是楊家槍法的“回馬槍”" NOR, me, target);
        addn_temp("apply/attack", me->query_skill("yangjia-qiang", 1) / 3, me);
        set_temp("yjq/hmq", 1, me);
        COMBAT_D->do_attack(me, target, query_temp("weapon", me), random(4)?1:3);
        addn_temp("apply/attack", -me->query_skill("yangjia-qiang", 1) / 3, me);
        me->delte_temp("yjq/hmq");
    }

}
