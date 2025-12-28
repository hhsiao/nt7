//開始閱讀文件：/kungfu/skill/bingxin-jue.c
//redl 2014
#include <ansi.h>;
inherit FORCE;

int valid_enable(string usage)
{
        return usage == "force";
}

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("bingxin-jue", 1);
        return lvl * lvl * 15 * 18 / 100 / 200;
}

int valid_force(string force)
{
        return 1;
}

int valid_learn(object me)
{
        if( query("gender", me) == "無性" && query("bingxin-jue", me)>99 )
                return notify_fail("你無根無性，陰陽不調，難以領會高深的冰心決。\n");

        if( query("int", me)<31 )
                return notify_fail("你覺得冰心決深奧無比，一時難以領會。\n");

        if ((int)me->query_skill("force", 1) < 200)
                return notify_fail("你的基本內功火候還不夠，還不能學習冰心決。\n");

        return ::valid_learn(me);
}

int practice_skill(object me)
{
        return notify_fail("冰心決只能用學(learn)的來增加熟練度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"bingxin-jue/" + func;
}

int help(object me)
{
        write(HIC"\n冰心決："NOR"\n");
        write(@HELP

    詩仙李白身懷的內功，來歷不明。聽說他對海外的青梅酒情有獨鍾。

        學習要求：
                悟性31，非太監
HELP
        );
        return 1;
}
