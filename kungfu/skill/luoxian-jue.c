#include <ansi.h>
// 落仙訣
inherit SKILL;
string type() { return "knowledge"; }

int is_fmsk() { return 1; }
string family_name() { return "唐門世家"; }

int valid_learn(object me) {
    if (me->query_skill("tangmen-throwing", 1) < 30)
        return notify_fail("你唐門暗器火候不足，無法研習落仙訣。\n");

    if(query("family/family_name", me) != family_name() )
        return notify_fail("落仙訣只能唐門世家弟子方可研習。\n");

    return 1;
}

int difficult_level() {
    return 2000;
}
