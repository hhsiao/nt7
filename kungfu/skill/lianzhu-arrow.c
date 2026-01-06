#include <ansi.h>

inherit SKILL;

int valid_enable(string usage) { return  usage == "arrow"; }

int valid_learn(object me) {
    return notify_fail("連珠箭法只能向郭靖請教(qingjiao)來學習！\n");
}

string perform_action_file(string action) {
    return __DIR__"lianzhu-arrow/" + action;
}

void skill_improved(object me) {
    int lvl;

    lvl = me->query_skill("lianzhu-arrow", 1);
    if(lvl >= 50 &&
        !query("can_perform/lianzhu-arrow/lianzhu", me) )
    {
        tell_object(me, HIC "你通曉了連珠箭法「" HIR "連珠箭法" HIC "」的奧秘。\n" NOR);
        set("can_perform/lianzhu-arrow/lianzhu", 1, me);
    }
}
