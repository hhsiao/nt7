//開始閱讀文件：/kungfu/skill/tangshi-jian.c
// tangshi-jian.c 唐詩劍法
// redl 2014

#include <ansi.h>;
#include <combat.h>

inherit SKILL;

int is_pbsk() { return 1; }

string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
    ([
        "action": "$N手中$w自左上方斜劈向下，跟著向後挺劍刺出，一招"HIC"「孤鴻海上來，池潢不敢顧」"NOR"，手中$w更不回頭，一劍劍點向$n的$l。",
        "lvl": 0,
        "skill_name": "孤鴻海上來，池潢不敢顧"
    ]),
    ([
        "action": "$N退了兩步，$w大開大闔，一聲吆喝，橫削三劍，一招"HIB"「哥翁喊上來，是橫不敢過」"NOR"直刺$n的$l",
        "lvl": 10,
        "skill_name": "哥翁喊上來，是橫不敢過"
    ]),
    ([
        "action": "突然間嗤嗤嗤三聲，$N向$n連刺三劍，一式"HIG"「俯聽聞驚風，連山若波濤」"NOR"，劍刃在$n的$l邊堪堪掠過，$n只覺$l涼颼颼地，大吃一驚，急忙倒退。",
        "lvl": 20,
        "skill_name": "俯聽聞驚風，連山若波濤"
    ]),
    ([
        "action": "$N手中$w遞出，一個虛招指向$n的左肩，反手卻使出一式"HIY"「落日照大旗，馬鳴風蕭蕭」"NOR"，由下而上$w疾刺$n的$l",
        "lvl": 30,
        "skill_name": "落日照大旗，馬鳴風蕭蕭"
    ]),
    ([
        "action": "$N一招"HIW"「舉頭望明月，低頭思故鄉」"NOR"，身子前傾，忽地回劍斜削，手中$w平平地向$n的$l揮去",
        "lvl": 40,
        "skill_name": "舉頭望明月，低頭思故鄉"
    ]),
    ([
        "action": "$N上身往左側一擰，一招"BLU"「長安一片月，萬戶搗衣聲」"NOR"，右手$w反手向$n的$l揮去",
        "lvl": 50,
        "skill_name": "長安一片月，萬戶搗衣聲"
    ]),
    ([
        "action": "$N左一招"MAG"「萬國仰宗周」"NOR"，右一招"HIM"「衣冠拜冕旒」"NOR"，劍鋒平指，一氣呵成橫掃$n的$l",
        "lvl": 60,
        "skill_name": "萬國仰宗周 衣冠拜冕旒"
    ])
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me) {
    if(query("max_neili", me)<1000 )
        return notify_fail("你的內力不夠。\n");
    if(me->query_skill("literate", 1 )<600 )
        return notify_fail("你的讀書寫字不夠。\n");
    if(me->query_skill("sword-cognize", 1 )<200 )
        return notify_fail("你的劍道修養不夠。\n");
    return 1;
}
int practice_skill(object me) {
    object weapon;

    if(!objectp(weapon = query_temp("weapon", me) )
        || query("skill_type", weapon) != "sword" )
        return notify_fail("你使用的武器不對。\n");
    if(query("qi", me)<30 || query("neili", me)<10 )
        return notify_fail("你的內力或氣不夠練唐詩劍法。\n");
    me->receive_damage("qi", 30);
    addn("neili", -10, me);
    return 1;
}
string query_skill_name(int level) {
    int i;
    for(i = sizeof(action); i > 0; i--)
        if(level >= action[i - 1]["lvl"])
        return action[i - 1]["skill_name"];
}
mapping query_action(object me, object weapon) {
    /* d_e = dodge_effect p_e = parry_effect f_e = force_effect m_e = damage_effect */
    int d_e1 = 40;
    int d_e2 = 60;
    int p_e1 = 10;
    int p_e2 = 30;
    int f_e1 = 50;
    int f_e2 = 100;
    int m_e1 = 10;
    int m_e2 = 110;
    int i, lvl, seq, ttl = sizeof(action);

    lvl = (int) me->query_skill("tangshi-jian", 1);
    for(i = ttl; i > 0; i--)
        if(lvl > action[i - 1]["lvl"])
    {
        seq = i; /* 獲得招數序號上限 */
        break;
    }
    seq = random(seq);       /* 選擇出手招數序號 */
    return ([
        "action": action[seq]["action"],
        "dodge": d_e1 + (d_e2 - d_e1) * seq / ttl,
        "parry": p_e1 + (p_e2 - p_e1) * seq / ttl,
        "force": f_e1 + (f_e2 - f_e1) * seq / ttl,
        "damage": m_e1 + (m_e2 - m_e1) * seq / ttl,
        "damage_type": random(2) ? "割傷" : "刺傷"
        ]);
}
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

string *shi = ({HIG "「花間一壺酒，獨酌無相親。」" HIW, HIG "「舉杯邀明月，對影成三人。」" HIW, HIG "「月既不解飲，影徒隨我身。」" HIW, HIG "「暫伴月將影，行樂須及春。」" HIW,
    HIG "「我歌月徘徊，我舞影零亂。」" HIW, HIG "「醒時同交歡，醉後各分散。」" HIW, HIG "「永結無情遊，相期邈雲漢。」" HIW});
string *ship = ({HIW "\n$N仗劍沉吟道###，霎時一股劍氣，化作透明絲線襲向$n" HIW "。\n" NOR,
    HIW "\n$N身法陡快，忽唸到###，突然間劍勢大變，纏向$n" HIW "。\n" NOR,
    HIW "\n$N清吟###，手裡劍氣猶如銀色月光瀉地，遍佈夜空將$n" HIW "籠罩。\n" NOR,
    HIW "\n$N黯然低吟###，猛然揮劍封住西面八方，$n" HIW "大驚失色。\n" NOR});

mixed hit_ob(object me, object victim, int damage_bonus) {
    //      mixed result;
    string msg;
    int lvl , flagli = 0;
    int idx, idx2, ap, dp, damage, damage2;
    int num = 200;
    object weapon = query_temp("weapon", me);
    object *obs;

    if((userp(me) && query("tianyishenjiu_time", me)<1 ) ||
        me->query_skill("literate", 1 )<600 ||
        me->query_skill("sword-cognize", 1 )<200
    )
    return 0;

    if(!objectp(weapon) || query("skill_type", weapon) != "sword"
        || me->query_skill_mapped("sword") != "tangshi-jian")
        return 0;
    if (query("id", me)=="li bai")
        flagli = 1;
    if (!flagli) {
        if (query_temp("tsj_cd_time", me) >= time())
            return 0;
        set_temp("tsj_cd_time", time() + 2, me);
    }

    ap = attack_power(me, "sword") + me->query_int()*50 + me->query_skill("sword-cognize", 1);
    ap += ap*(query("tianyishenjiu_time", me) / 50);
    damage = damage_power(me, "sword");
    damage += damage * query("jiali", me) / 1000;
    damage += damage * (me->query_skill("literate", 1 )) / 3500;
    damage += damage * (me->query_skill("sword-cognize", 1 )) / 2500;
    damage += damage*(query("tianyishenjiu_time", me) / 25);

    lvl = me->query_skill("tangshi-jian", 1) + me->query_skill("literate", 1 ) + me->query_skill("sword-cognize", 1 );
    lvl = lvl / 6000;
    if ((!flagli) && lvl > query("tianyishenjiu_time", me)) lvl = query("tianyishenjiu_time", me);
    if (lvl < 1) lvl = 1;
    if (lvl > 6) lvl = 6;
    idx2 = lvl + 1;
    while (lvl--) {
        num --;
        if (!num) break;
        if (flagli && random(5)) lvl++;
        obs = me->query_enemy();
        if (!obs || !arrayp(obs) || !sizeof(obs))
            break;
        else
            victim = obs[random(sizeof(obs))];
        if (! me->is_fighting(victim)) continue;
        idx = random(idx2);
        damage2 = damage + damage * idx / 2;
        message_combatd((replace_string(ship[random(sizeof(ship))], "###", shi[idx]) ), me, victim);
        dp = defense_power(victim, "parry") + victim->query_int()*50 + victim->query_skill("sword-cognize", 1 );
        if (ap / 2 + random(ap) > dp)
        {
            msg = COMBAT_D->do_damage(me, victim, ((!random(3)) ? REMOTE_ATTACK : WEAPON_ATTACK), damage2, 60 + random(query("int", me) * 2),
                HIY"只聞「噗嗤」！一聲，" + weapon->name() + HIY "已穿透$n" HIY "的胸膛，鮮血不斷湧出。\n" NOR, me , victim);
        } else
        {
            msg = HIC "$n" HIC "會心一笑，看出$N" HIC "這招中的破綻，隨意施招竟將這招化去。\n" NOR;
        }
        message_combatd(sort_msg(msg), me, victim);
    }
    return 1;

}


int help(object me) {
    write(HIC"\n唐詩劍法："NOR"\n");
    write(@HELP

    鐵骨墨萼梅念笙傳給他三個徒弟五雲手萬震山，陸地神龍言達
平，鐵鎖橫江戚長髮的劍法。
    傳說詩仙利用深厚的文學造詣和劍道修養，將此劍法發揮到了
極致。當然，也離不開酒的功勞。

        學習要求：
                內力1000
                讀書寫字600
                劍道修養200
HELP
    );
    return 1;
}
