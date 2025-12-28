// hua_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "hua_poison"; }

string chinese_name() { return "化毒"; }

string update_msg_others()
{
       return HIG "$N" HIG "的目光散亂，神色異常，臉上泛出一層黑氣。\n" NOR;
}

string update_msg_self()
{
        return HIB "忽然肺腑一陣劇痛，你體內的毒力發作了！\n" NOR;
}
