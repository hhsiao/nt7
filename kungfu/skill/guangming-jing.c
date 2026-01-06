#include <ansi.h>
// 明教 guangming-jing
inherit SKILL;
string type() { return "knowledge"; }

int is_fmsk() { return 1; }
string family_name() { return "明教"; }

int valid_learn(object me) {
    if (me->query_skill("jiuyang-shengong", 1) < 120)
        return notify_fail("你九陽神功火候不足，無法研習大雲光明經。\n");

    if(query("family/family_name", me) != family_name() )
        return notify_fail("大雲光明經只能明教弟子方可研習。\n");

    if (me->query_skill("qiankun-danuoyi", 1) < 150)
        return notify_fail("你乾坤大挪移修為不足，無法繼續研習大雲光明經。\n");

    return 1;
}

void skill_improved(object me) {
    if (me->query_skill("guangming-jing", 1) >= 500)
    {
        if(!query("mj_gift/str", me) )
        {
            addn("str", 1, me);
            set("mj_gift/str", 1, me);
            tell_object(me, "由於你的大雲光明經修煉達到500級，你的先天臂力增加提高了。\n");
        }
    }
}

int difficult_level() {
    return 2000;
}
