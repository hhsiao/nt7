// tianshen.c 真龍天神
// Created by rcwiz for yhonline

#include <ansi.h>

inherit F_CLEAN_UP;

int is_scborn() { return 1; }

string name() { return HIY "真龍天神" NOR; }

int perform(object me, string skill)
{
        return notify_fail(HIY "炎帝、黃帝、蚩尤同具真龍天神之像，擁有驚天動地\n"
                               "的能力，此能力僅傳於嫡系後人。獲得此技能者\n"
                               "則完成師門任務後獲取任務能力值獎勵\n"
                               "提高10%。\n" NOR);


}
