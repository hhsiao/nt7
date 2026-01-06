// This program is a part of NITAN MudLIB
// redl 2013/7
// fuyu-jian.c 覆雨劍法
/*
 * 知識技能支持  <-      心源外照，
 * 浪翻雲處，進入發呆狀態時才能依幾率提高，
 * 意味著不能同時做其他研究練習，加大了提高的難度。
 * 變相限制了這劍法無法練到絕頂高度，只是大米技能。
 */
//劍法排他性，以免兼學其他強力劍法
//限制男性專屬，對明玉功、越女劍等女性專屬武功做制衡


#include <ansi.h>
#include <combat.h>
inherit SKILL;

string type() { return "martial"; }
string martialtype() { return "skill"; }
//int action_po(object me, object victim, object weapon, int damage);//
//int action_busy(object me, object victim, object weapon, int damage);
//int action_damage(object me, object victim, object weapon, int damage);//
//int action_parry(object me, object victim, object weapon, int damage);
//int action_dodge(object me, object victim, object weapon, int damage);

//string *order = ({ ""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU"" });

string *parry_msg = ({
    NOR"$n雙手亂舞，隨意化出一條潮水般的"YEL"蛟龍"NOR"，完全消去了$P攻勢。\n"NOR,
    NOR"$n略縮手臂，漫天的"HIG"煙雨"NOR"光點爆開，一時之間$P眼裡滿是銀芒，急忙大驚退開。\n"NOR,
    NOR"$n暴喝一聲，右手挽起一串"HIY"劍花"NOR"玄妙無比，纏得$P是手忙腳亂，進退兩難。\n"NOR,
    NOR"$n手裡劍倏地不見，半空中一輪"HIC"明月"NOR"突顯並爆射開來，如雨的劍芒擋住了$P的攻勢。\n"NOR
});

mapping *action = ({
    ([
        "action": "$N手上的$w彈起點點毫光，使出「" HIB "一網情深" NOR "」劍花兒像一張網般，迎頭向$n罩去。",
        "force": 160,
        "attack": 150,
        "dodge": -100,
        "parry": -100,
        "damage": 120,
        "damage_type": "刺傷",
        "lvl": 0,
        "skill_name": "一網情深"
    ]),
    ([
        "action": "在$N快速的飛舞下$w響出尖嘯，一招「" YEL "怒蛟升海" NOR "」在空中爆出萬千雨點，像狂風般卷向$n。",
        "force": 230,
        "attack": 150,
        "dodge": -120,
        "parry": -100,
        "damage": 150,
        "damage_type": "刺傷",
        "lvl": 0,
        "skill_name": "怒蛟升海"
    ]),
    ([
        "action": "$N似醒還醉的眼忽地睜亮，一式「" HIR "醉眼睨虹" NOR "」爆出無法形容的精芒，$w化作數道長虹速度激增，電射$n的$l。",
        "force": 300,
        "attack": 180,
        "dodge": -140,
        "parry": -100,
        "damage": 180,
        "damage_type": "刺傷",
        "lvl": 0,
        "skill_name": "醉眼睨虹"
    ]),
    ([
        "action": "$N手裡劍芒再起，施展「" HIG "洞庭煙雨" NOR "」無數強光從$N懷裡暴起，化作千萬道$w圍擊$n。",
        "force": 400,
        "attack": 150,
        "dodge": -120,
        "parry": -90,
        "damage": 300,
        "damage_type": "刺傷",
        "lvl": 1000,
        "skill_name": "洞庭煙雨"
    ]),
    ([
        "action": "$N面含微笑，使出「" HIY "詩酒浣劍" NOR "」，$w挽起爆出一個個劍花扭成一串波紋，以奇怪的角度往$n刺去。",
        "force": 280,
        "attack": 280,
        "dodge": -140,
        "parry": -90,
        "damage": 200,
        "damage_type": "刺傷",
        "lvl": 2000,
        "skill_name": "詩酒浣劍"
    ]),
    ([
        "action": "$N手中的$w倏地不見，半空中的皎月寒光突然爆射開來正是「" HIC "明月依舊" NOR "」，閃爍的劍芒如光雨往$n的周圍十丈激射而下。",
        "force": 500,
        "attack": 260,
        "dodge": -120,
        "parry": -110,
        "damage": 300,
        "damage_type": "刺傷",
        "lvl": 3000,
        "skill_name": "明月依舊"
    ]),
    ([
        "action": "不知何時$N瞬間已欺近$n身前三尺，簡單一式「" HIM "彩雲不歸" NOR "」，手裡的$w化為半點星芒，微微一閃直刺$n的心臟。",
        "force": 450,
        "attack": 360,
        "dodge": -140,
        "parry": -110,
        "damage": 320,
        "damage_type": "刺傷",
        "lvl": 4000,
        "skill_name": "彩雲不歸"
    ])
});


int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }

string query_parry_msg(string limb) {
    return parry_msg[random(sizeof(parry_msg))];
}

int valid_learn(object me) {
    object ob;
    if(!(ob = query_temp("weapon", me) )
        ||  query("skill_type", ob) != "sword" )
        return notify_fail("你必須先找一把劍才能練劍法。\n");
    if(query("str", me)<23 )
        return notify_fail("你的臂力不足，無法理解覆雨劍法。\n");
    if(query("int", me)<30 )
        return notify_fail("你的悟性不足，無法理解覆雨劍法。\n");
    if(query("con", me)<28 )
        return notify_fail("你的根骨不足，無法理解覆雨劍法。\n");
    if(query("dex", me)<26 )
        return notify_fail("你的身法不足，無法理解覆雨劍法。\n");
    if(query("character", me) == "心狠手辣" )
        return notify_fail("你天性缺乏仁慈，無法理解覆雨劍法。\n");
    if(me->query_skill("sword", 1) < me->query_skill("fuyu-jian", 1) )
        return notify_fail("你的基本劍法造詣有限，無法理解更高深的覆雨劍法。\n");
    return 1;
}

int practice_skill(object me) {
    return notify_fail("覆雨劍法只能用學(learn)來增加熟練度。\n");
    /*
     * object weapon;
     * if( !objectp(weapon=query_temp("weapon", me) )
     * || query("skill_type", weapon) != "sword" )
     * return notify_fail("你使用的武器不對。\n");
     * if( query("qi", me)<2000 || query("neili", me)<800)
     * return notify_fail("你的內力或氣不夠練覆雨劍法。\n");
     * me->receive_damage("qi", 200);
     * addn("neili", -80, me);
     * return 1;*/
}

string query_skill_name(int level) {
    int i;
    for(i = sizeof(action); i > 0; i--)
        if(level >= action[i - 1]["lvl"])
        return action[i - 1]["skill_name"];
}

mapping query_action(object me, object weapon) {
    //      return action[random(sizeof(action))];
    int i, level;
    level = (int) me->query_skill("fuyu-jian", 1);
    for (i = sizeof(action); i > 0; i--)
        if (level >= action[i - 1]["lvl"])
        return action[NewRandom(i, 20, level / 5)];

}

/*
 * int action_damage(object me, object victim, object weapon, int damage)
 * {
 * string msg;
 * string*limbs=query("limbs", victim);
 * int dam;
 * int skill= me->query_skill("lonely-sword", 1);
 * if( !me->is_fighting(victim) ) return 0;
 * if( damage == RESULT_DODGE && !victim->is_busy()
 * &&  skill > 100
 * &&  objectp(weapon=query_temp("weapon", me) )
 * &&  query("neili", me)>100
 * &&  random(skill) > victim->query_skill("force",1)/2 ) //躲過
 * {
 * addn("neili", -50, me);
 * message_combatd("\n$N一聲長嘯:"HIW"「劍旋離身，劍嘯震山河」"NOR", 瞬間劍芒大作,朝$n激射而至！\n",me,victim);
 * dam=skill*2+query_temp("apply/damage", me);
 * dam-=query_temp("apply/armor", victim);
 * if (dam < 0 ) dam = 0;
 * victim->receive_damage("qi", dam);
 * msg = COMBAT_D->damage_msg(dam, "刺傷"); //此次傷害
 * msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
 * msg = replace_string(msg,"$w",query("name", weapon));
 * message_combatd(msg, me, victim);
 * COMBAT_D->report_status(victim);
 * return 1;
 * } else
 * if( damage > 0 && !victim->is_busy()
 * &&  skill > 100
 * &&  query("neili", me)>100
 * &&  random(skill) > victim->query_skill("force",1)/4)   //打中對方
 * {
 * addn("neili", -50, me);
 * message_combatd("\n$N突然悟出"HIW"「練精化氣, 練氣化神, 練神還虛」"NOR"之真理, 手中長劍突然消失, 朝$n飛至！\n",me,victim);
 * dam=skill+query_temp("apply/damage", me);
 * dam-=query_temp("apply/armor", victim);
 * if (dam < 0 ) dam = 0;
 * victim->receive_damage("qi",dam);
 * msg = COMBAT_D->damage_msg(skill*2, "刺傷"); //此次傷害
 * msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
 * msg = replace_string(msg,"$w",query("name", weapon));
 * message_combatd(msg,me,victim);
 * COMBAT_D->report_status(victim);
 * return 1;
 * }
 * return 1;
 * }

 * int action_po(object me, object victim, object weapon, int damage)
 * {
 * // 破對方武功、內功  為終極效果
 * int skill= me->query_skill("lonely-sword", 1);
 * string v_force = victim->query_skill_mapped("force");
 * int jiali;
 * if( !me->is_fighting(victim) ) return 0;
 * if( damage > 0 )// 打中對方 破內功 或者破內力
 * {
 * if( v_force && skill > 250
 * &&  random(skill/2) > random(victim->query_skill("force"))
 * &&  random(skill) > 200
 * &&  victim->query_map_skill("force")
 * &&  objectp(weapon=query_temp("weapon", me) )
 * &&  random(3)==1 )
 * {
 * addn("neili", -100, me);
 * victim->map_skill("force");
 * message_combatd(HIC "$N一劍得手，劍招源源而出，劍尖直刺$n丹田！\n",me,victim);
 * message_combatd(RED "$n只覺混身如遭電擊，真氣勁力紊亂難控，已然不能施展"+to_chinese(v_force)+"！\n" NOR,me,victim);
 * return 1;
 * } else
 * if( random(me->query_skill("lonely-sword",1)) > 100 &&
 * random(me->query_skill("sword",1))>100 &&
 * me->query_skill("force",1) > 120 &&
 * !victim->is_busy() ) {
 * addn("neili", -50, me);
 * if( query("neili", victim)>600 )
 * addn("neili", -500, victim);
 * else
 * set("neili", 0, victim);
 * message_combatd(HIC "\n$N一劍得手，劍招源源而出，欲將$n團團困住！\n",me,victim);
 * message_combatd(HIM "$n急運內力，使出渾身解數，方才脫出劍圈！\n"NOR , me, victim);
 * return 1;
 * }
 * }
 * else if( damage == RESULT_DODGE && !victim->is_busy()) //躲過  震懾對方
 * {
 * addn("neili", -50, me);
 * message_combatd(HIY "$n只覺$N劍中暗藏無數玄機，稍一膽怯，不敢攻上前去！\n"NOR,me,victim);
 * victim->start_busy(1+random(skill/50));
 * return 1;
 * }
 * else if ( damage == RESULT_PARRY ) //對手招架住 可順勢再創對手
 * {
 * jiali=query("jiali", me);
 * if (!jiali) jiali=10;
 * if( random(skill)>140 )
 * {
 * addn("neili", -50, me);
 * message_combatd(HIC "$N相交一招，已然看破$n武功套路，胸有成竹地刺出一劍!\n",me,victim);
 * victim->receive_wound("qi", (random(jiali)*2+100));
 * message_combatd(HIM"$N劍氣縱橫! 一道劍氣劃過了$n的胸口。結果鮮血狂噴!\n"NOR,me,victim);
 * COMBAT_D->report_status(victim,1);
 * }
 * return 1;
 * }
 * return 1;

 * }

 * int action_busy(object me, object victim, object weapon, int damage)
 * {
 * int skill=me->query_skill("lonely-sword",1);
 * if( !me->is_fighting(victim) ) return 0;
 * if( damage <= 0 && !victim->is_busy()
 * &&  skill > 100
 * &&  objectp(weapon=query_temp("weapon", me) )
 * &&  query("neili", me)>100
 * &&  random(query("combat_exp", me))>query("combat_exp", victim)/3)//威力極小,如果沒有上兩個則包括躲過和招架
 * {
 * addn("neili", -50, me);
 * message_combatd("$N頓然領悟了"HIW"「劍在神先, 綿綿不絕」"NOR"之真意, 劍尖瞬間爆出無數大大小小,\n正反斜直各種各樣的圓圈, 將$n團團困住。\n",me,victim);
 * victim->start_busy(2+random(skill/50));
 * return 1;
 * } else
 * if( damage > 0  && !victim->is_busy()
 * &&  skill > 100
 * &&  random(skill) > victim->query_skill("force",1)/3)
 * {
 * addn("neili", -30, me);
 * message_combatd(CYN"$N以意馭劍，畫出數個"RED"圓圈"CYN"，左右兼顧，將$n纏在正中！\n" NOR,me,victim);
 * victim->start_busy(1+random(skill/50));
 * }
 * return 1;
 * }

 * int action_dodge(object me, object victim, object weapon, int damage)
 * {
 * int skill=me->query_skill("lonely-sword",1);
 * string msg;
 * string*limbs=query("limbs", victim);
 * if( !me->is_fighting(victim)) return 0;
 * if( random(me->query_skill("lonely-sword",1)) >= 200 &&
 * random(me->query_skill("sword",1))>180 &&
 * me->query_skill("force",1) >= 200 &&
 * objectp(weapon=query_temp("weapon", me)) &&
 * victim->query_map_skill("dodge") ) {
 * addn("neili", -50, me);
 * victim->map_skill("dodge");
 * if( !victim->is_busy() )
 * victim->start_busy(random(3)+1);

 * msg = HIC "\n$N突然舉劍一刺，劍招隨便無章，卻莫明奇妙地突破了$n的攻勢，大出$n意料！\n" ;
 * msg += HIR"$n大吃一驚，竟然忘了閃避！\n"NOR;
 * message_combatd(msg,me,victim);
 * return 1;
 * }
 * else if( damage <= 0 && random(skill) > random(victim->query_skill("dodge",1)/3))
 * {
 * addn("neili", -50, me);
 * message_combatd("\n卻見$N飄身而上，半空中舉劍上挑，劍光已封住了$n身週數尺之地，攻得精巧無比！\n",me,victim);
 * victim->receive_damage("qi",skill/2);
 * msg = COMBAT_D->damage_msg(skill/2, "刺傷");
 * msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
 * msg=replace_string(msg,"$w",query("name", weapon));
 * message_combatd(msg,me,victim);
 * COMBAT_D->report_status(victim);
 * return 1;
 * }
 * return 1;
 * }

 * int action_parry(object me, object victim, object weapon, int damage)
 * {
 * int skill=me->query_skill("lonely-sword",1);
 * string msg;
 * string*limbs=query("limbs", victim);
 * if( !me->is_fighting(victim)) return 0;
 * if( damage == RESULT_DODGE &&
 * random(me->query_skill("lonely-sword",1)) > 140 &&
 * random(me->query_skill("sword",1))>140 &&
 * me->query_skill("force",1) >= 200 &&
 * objectp(weapon=query_temp("weapon", me)) &&
 * victim->query_map_skill("parry") ) {
 * addn("neili", -50, me);
 * victim->map_skill("parry");
 * if( !victim->is_busy() )
 * victim->start_busy(random(2)+1);

 * msg = HIC "\n$N舉劍反攻，後發先至地刺向$n，不僅把$n招術封死，更進一步發出攻擊！\n" NOR;
 * msg += HIY"$n難以看清劍招來勢,竟然忘了招架！\n"NOR;
 * message_combatd(msg,me,victim);
 * }
 * else if (damage <= 0 && random(skill) > random(victim->query_skill("parry",1)/3))
 * {
 * addn("neili", -50, me);
 * msg = "\n$N一個箭步縱到$n身前，手腕微顫，揮劍斜撩，橫削$n$l，劍法極盡靈動輕捷\n";
 * victim->receive_damage("qi",skill/2);
 * msg += COMBAT_D->damage_msg(skill/2, "刺傷"); //此次傷害
 * msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
 * msg = replace_string(msg,"$w",query("name", weapon));
 * message_combatd(msg,me,victim);
 * COMBAT_D->report_status(victim);
 * }
 * }
 */

int double_attack() { return 1; }

int query_effect_parry(object attacker, object me) {
    object weapon;
    int lvl;

    if(!objectp(weapon = query_temp("weapon", me)) ||
        query("skill_type", weapon) != "sword" )
        return 0;

    lvl = me->query_skill("fuyu-jian", 1);
    if (lvl < 200)  return 20;
    if (lvl < 1000) return 50;
    if (lvl < 1500) return 60;
    if (lvl < 2000) return 70;
    if (lvl < 2500) return 80;
    if (lvl < 3000) return 100;
    if (lvl < 4000) return 120;
    return 130;
}

/*
 * void skill_improved(object me)
 * {
 * int lvl, i;

 * i=query("int", me)/3;
 * lvl = me->query_skill("lonely-sword", 1);

 * if (lvl >= 20
 * && !query("can_perform/lonely-sword/jue", me))
 * {
 * tell_object(me, HIC "你通曉了獨孤九劍「" HIW "總決式" HIC "」的奧秘。\n" NOR);
 * set("can_perform/lonely-sword/jue", 1, me);
 * me->improve_skill("martial-cognize", 1500000);
 * me->improve_skill("martial-cognize", 1500000);
 * me->improve_skill("martial-cognize", 1500000);
 * }

 * if (lvl > 120
 * && query("can_perform/lonely-sword/qi", me) <= 100 )
 * {
 * if( me->add("can_perform/lonely-sword/qi",random(i))<100 )
 * {
 * tell_object(me, HIC "你對獨孤九劍「" HIW "破氣式"
 * HIC "」有了新的領悟。\n" NOR);
 * } else
 * {
 * tell_object(me, HIC "你通曉了獨孤九劍「" HIW "破"
 * "氣式" HIC "」的奧秘。\n" NOR);
 * me->improve_skill("martial-cognize", 1500000);
 * me->improve_skill("martial-cognize", 1500000);
 * me->improve_skill("martial-cognize", 1500000);
 * }
 * }

 * if (lvl > 150
 * && query("can_perform/lonely-sword/po", me) <= 100 )
 * {
 * if( me->add("can_perform/lonely-sword/po",random(i))<100 )
 * {
 * tell_object(me, HIC "你對獨孤九劍「" HIR "總破式"
 * HIC "」有了新的領悟。\n" NOR);
 * } else
 * {
 * tell_object(me, HIC "你通曉了獨孤九劍「" HIR "總"
 * "破式" HIC "」的奧秘。\n" NOR);
 * me->improve_skill("martial-cognize", 1500000);
 * me->improve_skill("martial-cognize", 1500000);
 * me->improve_skill("martial-cognize", 1500000);
 * }
 * }

 * if (lvl > 200
 * && query("can_perform/lonely-sword/yi", me) <= 100 )
 * {
 * if( me->add("can_perform/lonely-sword/yi",random(i))<100 )
 * {
 * tell_object(me, HIC "你對獨孤九劍「" HIR "劍意"
 * HIC "」有了新的領悟。\n" NOR);
 * } else
 * {
 * tell_object(me, HIC "你通曉了獨孤九劍「" HIR "劍"
 * "意" HIC "」的奧秘。\n" NOR);
 * me->improve_skill("martial-cognize", 1500000);
 * me->improve_skill("martial-cognize", 1500000);
 * me->improve_skill("martial-cognize", 1500000);
 * }
 * }
 * }*/

int difficult_level() {
    return 180;
    //        if( query("lonely-sword/nothing", me) )
    //                return 300;
    //        else
    //                      return 200;
}

mixed valid_damage(object ob, object me, int damage, object weapon) {
    mixed result;
    int ap, dp;
    object m_weapon;

    if ((int) me->query_skill("fuyu-jian", 1) < 200
        || !(m_weapon = query_temp("weapon", me) )
        ||  ! living(me)
        || query("skill_type", m_weapon) != "sword" )
    return;

    ap = ob->query_skill("count", 1) / 2;
    ap += ob->query_skill("parry");
    ap += ob->query_skill("dodge");

    dp = me->query_skill("parry", 1);
    dp += me->query_skill("fuyu-jian", 1);


    if((dp * 2 / 3 + random(dp)) > ap ) {
        result = ([ "damage": -damage ]);
        result += (["msg": parry_msg[random(sizeof(parry_msg))]]);
        message_vision("$N垂目盯著$n的攻勢，心底默數著...\n", me, ob);
        return result;
    }


    return result;

    /*
     * //         // 無招
     * //         if( query("lonely-sword/nothing", me) )
     * //         {
     * //                 if( n = ABILITY_D->check_ability(me, "def_power-dgjj-nothing") )
     * //                         dp += dp * n/100;
     * //if (me->query_skill("sword") * 2 / 3 + random(me->query_skill("sword")) >
     * //    ob->query_skill("parry"))
     * if( dp * 2 / 3 + random(dp) > ap )
     * {
     * result = ([ "damage": -damage ]);

     * result += (["msg" : HIC "$n" HIC "突然舉劍一刺，劍招隨意無章，"
     * "卻莫明奇妙地突破了$N的攻勢，大出$N意料。\n"
     * "$n一轉劍勢，劍招源源而出，對$N發動攻勢！\n" NOR]);
     * COMBAT_D->do_attack(me,ob,query_temp("weapon", me));
     * COMBAT_D->do_attack(me,ob,query_temp("weapon", me));
     * COMBAT_D->do_attack(me,ob,query_temp("weapon", me));

     * if (! ob->is_busy())
     * ob->start_busy(2 + random(2));
     * return result;
     * }
     * //
     * //         }

     * if (ap / 3 + random(ap) < dp)
     * {
     * result = ([ "damage": -damage ]);

     * switch (random(6))
     * {
     * case 0:
     * result += (["msg" : HIC "$n" HIC "突然舉劍一刺，劍招隨意無章，"
     * "卻莫明奇妙地突破了$N的攻勢，大出$N意料。\n"
     * "$n一轉劍勢，劍招源源而出，對$N發動攻勢！\n" NOR]);
     * COMBAT_D->do_attack(me,ob,query_temp("weapon", me));
     * COMBAT_D->do_attack(me,ob,query_temp("weapon", me));
     * COMBAT_D->do_attack(me,ob,query_temp("weapon", me));
     * break;
     * case 1:
     * result += (["msg" : HIC "$n" HIC "舉劍反攻，後發先至地刺向$N，不僅把"
     * "$N招術封死，更進一步發出攻擊！\n" NOR]);
     * COMBAT_D->do_attack(me,ob,query_temp("weapon", me));
     * break;
     * case 2:
     * result += (["msg" : HIC "$n" HIC "提劍回刺，落點正是$N的破綻，"
     * "$N不得不撤招嚴守，身形一晃間已退出丈許！\n" NOR]);
     * break;
     * case 3:
     * result += (["msg" : HIC "卻見$n" HIC "踏前一步，劍式斜指$P" HIC
     * "右臂，招式迅捷無比，使得$N" HIC "閃身而退"
     * "。\n" NOR]);
     * break;
     * case 4:
     * result += (["msg" : HIC "$n" HIC "突然一劍點向$N" HIC "，雖一劍"
     * "卻暗藏無數後著，$N" HIC "頓時手足無措，攻"
     * "勢不由自主停了下來。\n" NOR]);
     * break;
     * default:
     * result += (["msg" : HIC "$n" HIC "眼見避無可避，只好提劍亂刺一通，"
     * "居然出乎意料地將$N的攻擊接去。\n" NOR]);
     * break;
     * }

     * return result;
     * } else
     * if (mp >= 100)
     * {
     * switch (random(3))
     * {
     * case 0:
     * result = HIY "$n" HIY "一抖手中的" + m_weapon->name() +
     * HIY "，中攻直進一劍挺進，可是$N" HIY "反招更快"
     * "，進襲$n" HIY "！\n" NOR;
     * break;

     * case 1:
     * result = HIY "$n" HIY "手中" + m_weapon->name() + "輕挑"
     * "，" HIY "正指向$N" HIY "攻勢中的破綻，可是$N"
     * HIY "身形一變，破綻立刻不成為破綻。\n" NOR;
     * break;

     * default:
     * result = HIY "$n" HIY "手中" + m_weapon->name() + HIY
     * "續變換數種劍招，然而$N" HIY "理也不理，再次攻"
     * "出，絲毫不受$n" HIY "的迷惑。\n"  NOR;
     * break;
     * }
     * COMBAT_D->set_bhinfo(result);
     * }
     */
}

/*
 * mixed hit_ob(object me, object victim, int damage_bonus)
 * {
 * mixed result;
 * int lvl;
 * object weapon, weapon2;
 * int i, ap, dpp, dpd, dpf;
 * string type, msg, msg1;

 * lvl = me->query_skill("lonely-sword", 1);

 * if( query("neili", me)<300
 * ||  me->query_skill_mapped("sword") != "lonely-sword"
 * || !objectp(weapon=query_temp("weapon", me) )
 * || query("skill_type", weapon) != "sword"
 * || !query("lonely-sword/nothing", me) )
 * return 0;

 * ap = me->query_skill("sword");
 * dpp = victim->query_skill("parry");
 * dpd = victim->query_skill("dodge");
 * dpf = victim->query_skill("force");

 * switch(random(3))
 * {
 * case 1:
 * if (ap * 3 / 4 + random(ap) > dpp)
 * {
 * addn("neili", -100, me);
 * result = ([ "damage" : damage_bonus ]);

 * msg1 = random(2) ? HIR "$N" HIR "一劍攻出，劍氣橫飛，" + weapon->name() + HIR
 * "時若游龍穿空，時若驚鴻渡雲，卻不知這普通的"
 * "一劍之中竟蘊藏著如此威力。\n" NOR:
 * HIR "$N" HIR "手中" + weapon->name() + HIR "猶"
 * "如生了眼睛一般，一劍隨意揮出，竟直刺向$n" HIR
 * "小腹，看似平淡，但方位、力道卻拿捏得恰倒好處。\n" NOR;
 * result += ([ "msg" : msg1 ]);
 * return result;
 * }
 * break;

 * case 2:
 * message_combatd(HIC "\n$N" HIC "隨意揮灑手中的" + weapon->name() +
 * HIC "，招招從出其不意的方位直指$n" HIC "招式中的"
 * "破綻！\n" NOR, me, victim);

 * if (! me->is_busy())
 * {
 * weapon=query_temp("weapon", me);
 * weapon2=query_temp("weapon", victim);
 * if( weapon2)type=query("skill_type", weapon2);


 * if (ap * 3 / 4 + random(ap) >= dpf && weapon2
 * &&  type != "pin")
 * {
 * msg = HIW "$n" HIW "覺得眼前眼花繚亂，手中"
 * "的" + weapon2->name() + HIW "一時竟"
 * "然拿捏不住，脫手而出！\n" NOR;
 * weapon2->move(environment(me));
 * addn("neili", -100, me);
 * } else
 * {
 * msg = HIY "$n" HIY "略得空隙喘息，一時間卻"
 * "也無力反擊。\n" NOR;
 * addn("neili", -40, me);
 * }
 * }else
 * if (ap * 4 / 5 + random(ap) > dpd)
 * {
 * msg = HIY "$n" HIY "連忙抵擋，一時間不禁手忙腳亂，"
 * "無暇反擊。\n" NOR;

 * if (! victim->is_busy())
 * victim->start_busy(1 + random(lvl / 30));
 * }
 * else
 * {
 * msg = HIC "$N" HIC "隨意揮灑著手中的" + weapon->name() +
 * HIC "刺向$n" HIC "，不過$n" HIC "防守的異常嚴密，$N"
 * HIC "一時竟然無法找到破綻。\n" NOR;
 * if (! victim->is_busy())
 * victim->start_busy(1);
 * }
 * message_combatd(msg, me, victim);
 * break;

 * default :
 * if (ap * 2 / 3 + random(ap) > dpd &&
 * ! me->is_busy() &&
 * ! random(2) &&
 * !query_temp("lonely-sword/lian", me) )
 * {
 * weapon=query_temp("weapon", me);
 * message_combatd(HIY "\n$N" HIY "胸藏劍意，手中" + weapon->name() + HIY
 * "隨意揮灑而出，速度之快，方位之準，\n顯是獨孤九劍已達到"
 * "收發自如的境界。\n" NOR,
 * me, victim);

 * addn("neili", -270, me);

 * set_temp("lonely-sword/lian", 1, me);
 * for (i = 0; i < 5; i++)
 * {
 * if (! me->is_fighting(victim))
 * break;

 * if (! victim->is_busy() && random(2) == 1)
 * victim->start_busy(1);

 * COMBAT_D->do_attack(me, victim, weapon, 0);
 * }
 * delete_temp("lonely-sword/lian", me);

 * }
 * break;
 * }
 * }
 */

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

int valid_effect(object me, object weapon, string name, int skill) {
}
string perform_action_file(string action) {
    return __DIR__"lonely-sword/" + action;
}

int help(object me) {
    write(HIC"\n獨孤九劍："NOR"\n");
    write(@HELP

    “獨孤九劍，有進無退！”
    創制這套劍法的獨孤求敗前輩，名字叫做‘求敗’，他畢生想
求一敗而不可得，這劍法施展出來，天下無敵，當年他仗劍江湖，
無敵於天下，連找一個對手來逼得他回守一招都不可得，委實令人
可驚可佩。
    無招勝有招，敵強我更強。獨孤九劍不含招式，有招既無招，
無招亦有招。獨孤九劍要旨在於「悟」，不可拘泥不化，講究料敵
機先，出奇制勝。通曉了九劍劍意，則無所施而不可。
    獨孤九劍，自“總訣式”、“破劍式”、“破刀式”以至“破
槍式”、“破鞭式”、“破索式”、“破掌式”、“破箭式”而到
第九劍“破氣式”。九劍的第一招“總訣式”，有種種變化，用以
體演總訣，便於修習。第二招“破劍式”，用以破解普天下各門各
派的劍法。第三招“破刀式”，用以破解單刀、雙刀、柳葉刀、鬼
頭刀、大砍刀、斬馬刀種種刀法。第四招“破槍式”，包括破解長
槍、大戟、蛇矛、齊眉棍、狼牙棒、白蠟杆、禪杖、方便鏟種種長
兵刃之法。第五招“破鞭式”，用以破解鋼鞭、鐵鐧、點穴橛、拐
子、蛾眉刺、匕首、板斧、鐵牌、八角槌、鐵椎等等短兵刃，第六
招“破索式”，破解的是長索、軟鞭、三節棍、鏈子槍、鐵鏈、漁
網、飛錘流星等等軟兵刃。第七招“破掌式”，破的是拳腳指掌上
的功夫，將長拳短打、擒拿點穴、魔爪虎爪、鐵沙神掌，諸般拳腳
功夫盡數包括內在。第八招“破箭式”這個“箭”字，則總羅諸般
暗器，練這一劍時，須得先學聽風辨器之術，不但要能以一柄長劍
擊開敵人發射來的種種暗器，還須借力反打，以敵人射來的暗器反
射傷敵。第九劍“破氣式”，是為對付身具上乘內功的敵人而用，
神而明之，存乎一心。

        學習要求：
                只能向風清揚學習
                紫霞神功100級
                內力600
HELP
    );
    return 1;
}
