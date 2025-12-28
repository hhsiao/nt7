// wugong_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "wugong_poison"; }

string chinese_name() { return "蜈蚣毒"; }

string update_msg_others()
{
       return HIG "$N" HIG "的身體一震，神色發散，七竅開始向外流血。" NOR;
}

string update_msg_self()
{
        return HIG "你覺得傷口火辣辣地痛，不禁皺了皺眉頭。你中的蜈蚣毒發作了！\n" NOR;
}
