// warn_poison 硃砂掌毒

#include <ansi.h>;
#include <condition.h>;
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        if (me->is_ghost()) return 1;
        if( !living(me) || query_temp("noliving", me) )
        {
                message("vision", me->name()+"喘著粗氣，面色赤紅。\n", environment(me), me);
        }
        else
        {
                tell_object(me, RED"你只覺渾身燥熱難耐，似乎被放在火爐中一樣，極為難受！\n" NOR );
                message("vision", RED+me->name()+"突然面色一紅，渾身一抖，自頭部到手臂隱約可見斑斑紅點，極為恐怖。\n"NOR, environment(me), me);
        }
        me->receive_damage("qi", 2500);
        me->receive_wound("jing", 2000);
        if( query("eff_jing", me)<0 || query("eff_qi", me)<0)
        {
                set_temp("die_reason", "硃砂掌毒發作死亡");
                return 0;
        }
        me->apply_condition("warm_poison", duration - 1);
        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}

string query_type(object me)
{
        return "poison";
}