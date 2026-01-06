// black_poison 黑砂掌毒

#include <ansi.h>;
#include <condition.h>;
inherit F_CLEAN_UP;

int update_condition(object me, int duration) {
    if (me->is_ghost()) return 1;
    if(!living(me) || query_temp("noliving", me) )
    {
        message("vision", me->name() + "喘著粗氣，中掌處黑絲如墨。\n", environment(me), me);
    }
    else
    {
        tell_object(me, HIB"你只覺渾身冰冷刺骨，甚為難受！\n" NOR );
        message("vision", HIB + me->name() + "突然面色鐵青，全身上下黑絲隱約可辨，看來是中了黑砂掌後掌毒發作了。\n"NOR, environment(me), me);
    }
    me->receive_damage("qi", 2500);
    me->receive_wound("jing", 2000);
    if(query("eff_jing", me)<0 || query("eff_qi", me)<0)
    {
        set_temp("die_reason", "黑砂掌毒發作死了", me);
        return 0;
    }
    me->apply_condition("black_poison", duration - 1);
    if(duration < 1 ) return 0;
    return CND_CONTINUE;
}

string query_type(object me) {
    return "poison";
}
