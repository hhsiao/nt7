#include <ansi.h>
inherit SKILL;

mapping *action = ({
    ([
        "action": "$N劃身錯步，一式「追風逐電」，雙掌內攏外託，同時攻向$n的左肩",
        "force": 170,
        "attack": 85,
        "dodge": -38,
        "parry": -38,
        "damage": 36,
        "lvl": 0,
        "skill_name": "追風逐電",
        "damage_type": "內傷"
    ]),
    ([
        "action": "$N一式「雲飄四海」，雙掌虛虛實實，以迅雷不及掩耳之勢劈向$n",
        "force": 210,
        "attack": 98,
        "dodge": -43,
        "parry": -43,
        "damage": 44,
        "lvl": 40,
        "skill_name": "雲飄四海",
        "damage_type": "內傷"
    ]),
    ([
        "action": "$N使一式「八方雲湧」，勁氣瀰漫，雙掌如輪，一環環向$n的後背斫去",
        "force": 280,
        "attack": 103,
        "dodge": -51,
        "parry": -51,
        "damage": 58,
        "lvl": 80,
        "skill_name": "八方雲湧",
        "damage_type": "內傷"
    ]),
    ([
        "action": "$N一式「龍捲暴伸」，雙掌似讓非讓，似頂非頂，氣浪如急流般使$n陷身其中",
        "force": 340,
        "attack": 125,
        "dodge": -65,
        "parry": -65,
        "damage": 67,
        "lvl": 120,
        "skill_name": "龍捲暴伸",
        "damage_type": "內傷"
    ]),
    ([
        "action": "$N一式「冰封萬里」，掌影層層疊疊，飄飄渺渺，凌厲的掌風直湧$n而去",
        "force": 370,
        "attack": 131,
        "dodge": -68,
        "parry": -68,
        "damage": 71,
        "lvl": 160,
        "skill_name": "冰封萬里",
        "damage_type": "內傷"
    ]),
    ([
        "action": "$N雙手變幻，五指輕彈，一招「穹寰飛仙」，力分五路，招劃十方籠罩$n",
        "force": 410,
        "attack": 145,
        "dodge": -73,
        "parry": -73,
        "damage": 82,
        "lvl": 200,
        "skill_name": "穹寰飛仙",
        "damage_type": "內傷"
    ])
});

int valid_enable(string usage) { return usage == "strike" ||  usage == "parry"; }

int valid_learn(object me) {
    if(query_temp("weapon", me) || query_temp("secondary_weapon", me) )
        return notify_fail("練飄雪穿雲掌必須空手。\n");

    if(query("con", me)<28 )
        return notify_fail("你的先天根骨欠佳，不能練飄雪穿雲掌。\n");

    if(query("str", me)<32 )
        return notify_fail("你的先天臂力孱弱，不能練飄雪穿雲掌。\n");

    if (me->query_skill("force") < 200)
        return notify_fail("你的內功火候不夠，不能練飄雪穿雲掌。\n");

    if (me->query_skill("strike", 1) < 200)
        return notify_fail("你的掌法根基不夠，不能練飄雪穿雲掌。\n");

    if(query("max_neili", me)<5800 )
        return notify_fail("你的內力修為太淺，無法練飄雪穿雲掌。\n");

    if (me->query_skill("strike", 1) < me->query_skill("piaoxue-zhang", 1))
        return notify_fail("你的基本掌法太差，無法領會更高深的飄雪穿雲掌。\n");

    return 1;
}

string query_skill_name(int level) {
    int i;
    for(i = sizeof(action) - 1; i >= 0; i--)
        if(level >= action[i - 1]["lvl"])
        return action[i - 1]["skill_name"];
}

mapping query_action(object me, object weapon) {
    int i, level;
    level = (int)me->query_skill("piaoxue-zhang", 1);
    for(i = sizeof(action); i > 0; i--)
        if(level > action[i - 1]["lvl"])
        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me) {
    return notify_fail("飄雪穿雲掌無法簡單的通過練習進步。\n");
    /*
     * if( query("qi", me)<100 )
     * return notify_fail("你的體力太低了。\n");

     * if( query("neili", me)<120 )
     * return notify_fail("你的內力不夠練習飄雪穿雲掌。\n");

     * if (me->query_skill("sixiang-zhang", 1) < 100)
     * {
     * me->receive_damage("qi", 60);
     * addn("neili", -80, me);
     * } else
     * {
     * me->receive_damage("qi", 80);
     * addn("neili", -100, me);
     * }
     * return 1;*/
}

mixed hit_ob(object me, object victim, int damage_bonus) {
    int lvl, lv2;
    int i;

    lvl = me->query_skill("piaoxue-zhang", 1);

    if(query_temp("piaoxue-zhang/lian", me) < time() &&
        query("neili", me) > 500 &&
        me->query_skill_mapped("dodge") == "zhutian-bu" &&
        !random((BUFF_D->check_buff(me, "ljz-niepan")) ? 2 : 4) &&
        !me->is_busy()) {
        i = lvl / 1000;
        i = 1 + random(i);
        if (i > 2) i = 2;
        addn("neili", -250, me);
        set_temp("piaoxue-zhang/lian", time() + 2 + random(2), me);
        message_combatd(NOR CYN "\n$N" NOR CYN + (random(2) ? "腳踏": "急踩") + "諸天步法，飄飄渺渺間向$n" NOR CYN "斫出數掌。\n" NOR,
            me, victim);
        while (i--) {
            if (! me->is_fighting(victim)) break;
            COMBAT_D->do_attack(me, victim, 0, 3);
        }
        //delete_temp("piaoxue-zhang/lian", me);
    }

    if (damage_bonus < 120 || lvl < 1500) return 0;

    if (random(me->query_str()) > victim->query_con() / 2)
    {
        lv2 = me->query_skill("emei-jiuyang", 1);
        if (lv2 > 200)
        {
            if (query("neili", me) < query("max_neili", me))  addn("neili", lv2, me);
            victim->receive_wound("qi", damage_bonus * 2, me);
            return NOR HIR "$N" HIR "的" HIW "峨眉九陽" HIR "勁力透掌心，只聽$n" HIR "前胸“喀嚓”爆響，竟似折斷了數根肋骨。\n" NOR;
        } else {
            victim->receive_wound("qi", damage_bonus / 3, me);
            return HIR "只聽$n" HIR "前胸“喀嚓”一聲悶響，竟似折斷了一根肋骨。\n" NOR;
        }
    }
    return 0;
}

string perform_action_file(string action) {
    return __DIR__"piaoxue-zhang/"+ action;
}

mixed valid_damage(object ob, object me, int damage, object weapon)     //by redl
{
    mixed result;
    int ap, dp, mp;
    int delta = 0;
    string msg = NOR;
    int flagd = 0;

    delta = ABILITY_D->check_ability(me, "parryup-piaoxue-zhang");  // 門派ab 飄雪掌招架幾率+25%
    //DEBUG_CHANNEL(query("id", me) + " 飄雪掌 delta:" + (string)delta + "\n");
    if(random(100) > 65 + delta ) return;

    if ((int)me->query_skill("emei-jiuyang", 1) < 120 ||
        (int)me->query_skill("jiuyin-baiguzhao", 1) < 120 ||
        (int)me->query_skill("piaoxue-zhang", 1) < 120 ||
        (me->query_skill_mapped("claw") != "jiuyin-baiguzhao") ||
        (me->query_skill_mapped("parry") != "piaoxue-zhang") ||
    //                (me->query_skill_prepared("strike") != "piaoxue-zhang") ||
        !living(me) || query_temp("weapon", me) )
    return;

    mp = ob->query_skill("count", 1);
    ap = mp + ob->query_skill("parry", 1) / 3;
    ap += ob->query_skill("force", 1) / 3;
    ap += ob->query_skill("dodge", 1) / 3;
    dp = me->query_skill("piaoxue-zhang", 1) / 2;
    dp += me->query_skill("emei-jiuyang", 1) / 3;
    dp += me->query_skill("jiuyin-baiguzhao", 1) / 3;
    dp += dp * me->query_skill("jingxin", 1) / 1200;

    //DEBUG_CHANNEL("ap:" + (string)ap + "  dp:" + (string)dp + "\n");
    if (random(ap) < dp / 2)
    {
        result = ([ "damage": -damage ]);
        if(((int)me->query_skill("emei-jiuyang", 1) >= 2000) &&
            random(5) &&
            query_temp("block_msg/all", me) ) {
            msg += NOR HIW "$n" HIW "運轉九陽真氣直衝瞳子，雙眼恢復晴明。\n" NOR;
            delete_temp("block_msg/all", me);
        }
        switch (random(3))
        {
        case 0:
            msg += HIW "$n" HIW "變掌為爪，五指狠扣將$N" HIW "的攻勢牢牢按住。\n" NOR;
            if (query("neili", me) < query("max_neili", me))  addn("neili", dp, me);
            addn("neili", - dp, ob);
            if (query("neili", ob) < 0) set("neili", 0, ob);
            break;
        case 1:
            msg += HIW "$n" HIW "肩膀微側，體內峨眉九陽勁一震，抖開$N" HIW "的進攻。\n" NOR;
            if (!random(3))
                delete_temp("no_exert", me);
            if (!random(3))
                delete_temp("no_perform", me);
            break;
        default:
            if (weapon && objectp(weapon)   //&&
            //(query("skill_type", weapon) == "sword" || query("skill_type", weapon) == "pin")
            ) {
                if (!random(25)) {
                    flagd = 1;
                } else
                if (!random(3) &&   //33%破辟邪
                    (query("skill_type", weapon) == "sword" || query("skill_type", weapon) == "pin") &&
                    ((ob->query_skill_mapped("sword") == "kuihua-mogong") || (ob->query_skill_mapped("sword") == "pixie-jian"))
                ) {
                    flagd = 1;
                }
                if (flagd) {
                    msg += HIW "$n" HIW "豎掌往前一抓，九陰爪勁力射出指尖，$N" HIW "手裡的" + query("name", weapon) + "被擊落。\n" NOR;
                    weapon->move(environment(ob));
                }
            } else
            msg += HIW "$n" HIW "豎掌往前一抓，九陰爪勁力射出指尖，$N" HIW "不得已被迫退。\n" NOR;
            //COMBAT_D->do_attack(me, ob, 0, 3);
            break;
        }
        result += (["msg": msg]);
        return result;
    } else
    if (mp >= 100)
    {
        switch (random(3))
        {
        case 0:
            result = HIW "$n" HIW "攤開手掌，五根鐵指狠扣向$N" HIW "的攻勢按去。\n" NOR;
            break;
        case 1:
            result = HIW "$n" HIW "肩膀微側，體內峨眉九陽勁一震，抖開$N" HIW "的進攻。\n" NOR;
            break;
        default:
            result = HIW "$n" HIW "豎掌往前一抓，九陰爪勁力射出指尖，欲將$N" HIW "迫退。\n" NOR;
            break;
        }
        switch (random(2))
        {
        case 0:
            result += HIY "然而$N" HIY "理也不理，隨手揮招直入，進襲$n" HIY "！\n" NOR;
            break;
        default:
            result += HIY "可是$N" HIY "攻勢卻是變化無方，不遵循常理。\n" NOR;
            break;
        }
        COMBAT_D->set_bhinfo(result);
    }
}

int difficult_level() {
    int i = 1300;
    object me = this_object();
    if (me->query_skillo("buddhism", 1) > 999)
        i -= 100;
    if (me->query_skillo("mahayana", 1) > 999)
        i -= 100;
    if (me->query_skillo("jingxin", 1) > 999)
        i -= 100;
    if (me->query_skillo("jingxin", 1) > 1999)
        i -= 100;
    return i;
}
