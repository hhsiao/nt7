#include <ansi.h>
inherit SKILL; 
string type() { return "knowledge"; } 

int is_fmsk() { return 1; }
string family_name() { return "神龍教"; }

int valid_learn(object me)
{        
        if (me->query_skill("busi-shenglong", 1) < 120)
                return notify_fail("你不死神龍火候不足，無法研習神龍大法。\n");
        
        if( query("family/family_name", me) != family_name() )
                return notify_fail("神龍大法只能神龍教弟子方可研習。\n");

        return 1;
}

int difficult_level()
{
        return 2000;
}
