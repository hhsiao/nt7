#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

#include "force.h"

int valid_learn(object me) {
    int i, l;
    i = (int)me->query_skill("qiantian-yiyang", 1);
    l = (int)me->query_skill("buddhism", 1);

    if (!me->query("tls"))
        if ((i >= 10 && (int)me->query("shen") < i * 5)
        || (i >= 50 && (int)me->query("shen") < i * 8)
        || (i >= 100 && (int)me->query("shen") < i * 10))
    return notify_fail("大理乃是明門正派，看來你的俠義正氣還不夠啊！\n");

    if (me->query("tls") && i > 10 && i < 150 && l < i - 10)
        return notify_fail("你的佛學修為看來不能抑止你的心中的好勝之心了！\n");

    if (me->query_skill("force", 1) < 20)
        return notify_fail("你的基本內功火候還不夠，無法領會乾天一陽功。\n");

    if (i > 99 && (string)me->query("gender") != "男性")
        return notify_fail("你不是純陽之身，無法領會更高層的乾天一陽功。\n");

    if (me->query("menggu"))
        return notify_fail("乾天一陽功怎可和邪派功夫混為一體？\n");

    if (i > me->query_skill("force", 1) + 10 && i >= 200 )
        return notify_fail("你的基本功火候未到，必須先打好基礎才能繼續提高。\n");

    return valid_public(me);
}

int practice_skill(object me) {
    if((int)me->query_skill("qiantian-yiyang", 1) >= 200) {
        if((int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200) {
            me->improve_skill("qiantian-yiyang", (int)me->query_int());
            me->add("neili", -100);
            me->add("potential", -1*(1 + random(3)));
            return 1;
        }
        else return notify_fail("你現在的修為不足以提高乾天一陽功了。\n");
    }
    else return notify_fail("你現在的乾天一陽功修為只能用學(learn)的來增加熟練度。\n");
}

string exert_function_file(string func) {
    return __DIR__"qiantian-yiyang/" + func;
}

mapping exercise_msg(object me) {
    return ([
        "status_msg": HIY + me->name() + "結珈而坐，神態安詳"NOR,
        "start_my_msg": "你盤膝坐下，閉目合什，運起乾天一陽神功，一股純陽真氣開始在體內運轉。\n",
        "start_other_msg": me->name() + "盤膝坐下，閉目合什,神態安詳，周身似乎有一層金光籠罩。\n",
        "halt_msg": "$N雙掌一分，平攤在胸，迅速收氣，停止真氣的流動。\n",
        "end_my_msg": "你真氣在體內運行了一個周天，緩緩收氣于丹田，慢慢睜開了眼睛。\n",
        "end_other_msg": "只見"+me->name() + "慢慢睜開眼睛，周身籠罩的金光逐漸隱去。\n"
        ]);
}

int ob_hit(object ob, object me, int damage) {
    int i, neili, j;

    if(!me->query_temp("dali/jujing") ) return 0;

    if (me->query_temp("weapon")) return 0;

    if (me->query_skill_mapped("finger") != "yiyang-zhi"
        || me->query_skill_prepared("finger") != "yiyang-zhi") return 0;

    if(me->is_busy() ) j = 2; else j = 1;

    if(damage > me->query("qi") / 2 ) {
        me->add_temp("dali/jujing1", damage*j);
        neili = 13000 - me->query_skill("force")*10;
        if(neili < me->query("neili") ) {
            me->add("neili",-neili);
            if(wizardp(me) && me->query("env/test") )
                tell_object(me, sprintf("dec: %d,%d\n", damage, neili));
            message_vision(CYN"$N以一陽指柔勁吸收掉$n全部的攻擊。\n"NOR, me, ob);
            return -damage;
        }
    }

    //if( random(me->query("combat_exp")) < ob->query("combat_exp")/3 ) return 0;

    i = me->query_skill("force") / 10;
    i = min(i, 70);
    i = i / 3 + random(i);
    i = damage * i / 100;

    me->add_temp("dali/jujing1", i*j);
    if(wizardp(me) && me->query("env/test") )
        tell_object(me, sprintf("dec: %d(%d) \n", i, damage));
    message_vision(CYN"$N以一陽指柔勁吸收掉$n部分攻擊。\n"NOR, me, ob);

    return -i;
}
