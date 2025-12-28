// This program is a part of NT MudLIB
// hebi.c 全真劍之與玉女劍合璧

#include <ansi.h>

inherit F_SSERVER;

string name() { return "雙劍合璧"; }

void check_fight(object me, object target, object victim);

int perform(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill, skill1, skill2;
        object victim;
        object weapon;

        if( !victim ) victim = offensive_target(me);

        if( !victim || !victim->is_character() || !me->is_fighting(victim) )
                return notify_fail("雙劍合璧只能對戰鬥中的對手使用。\n");

        if( !target )
                return notify_fail("你想與誰進行雙劍合璧？\n");

        if( query("id", victim) == query("id", target) )
                return notify_fail("不能與敵人進行雙劍合璧！\n");

        if( !target->is_fighting(victim) )
                return notify_fail("你想與其雙劍合璧的對象並未與你的敵人搏鬥！\n");

        if( target->query_skill_mapped("sword") != "yunv-jian" )
                return notify_fail("你想與其雙劍合璧的對象所使用的並非玉女劍法！\n");

        if( !objectp(weapon=query_temp("weapon", target) )
                 || query("skill_type", weapon) != "sword" )
                return notify_fail("你想與其雙劍合璧的對象並沒有用劍！\n");

        if( BUFF_D->check_buff(me, "quanzhen_hebi") )
                return notify_fail("你正與別人進行雙劍合璧。\n");

        if( BUFF_D->check_buff(target, "yunv_hebi") )
                return notify_fail("你想與其雙劍合璧的對象正與他人合壁戰鬥中，無暇與你合璧！\n");

        skill1 = me->query_skill("sword");
        skill2 = target->query_skill("sword");
        skill =  ( skill1 + skill2 ) / 4;

        if( mapp(query("couple", me)) &&
            query("couple/couple_id", me) == query("id", target) )
        skill += skill/2;

        msg = HIR "\n$N與$n突然間雙劍一交，全真劍法與玉女劍法配合得天衣無縫，攻勢及守勢驟然大增！\n\n" NOR;

        data = ([
                "attack": skill/2,
                "damage": skill,
                "dodge": skill/2,
                "parry": skill/2, 
        ]);

        buff = ([
                "caster": me,
                "target": me,
                "type"  : "quanzhen_hebi",
                "attr"  : "bless",
                "name"  : "全真劍法·雙劍合璧",
                "time"  : skill/2,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的雙劍合璧運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);
        
        buff = ([
                "caster": target,
                "target": target,
                "type"  : "yunv_hebi",
                "attr"  : "bless",
                "name"  : "玉女劍法·雙劍合璧",
                "time"  : skill/2,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的雙劍合璧運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);

        addn_temp("apply/damage", skill, me);
        addn_temp("apply/damage", skill, target);
        COMBAT_D->do_attack(me,victim,query_temp("weapon", me));
        COMBAT_D->do_attack(target,victim,query_temp("weapon", target));
        COMBAT_D->do_attack(me,victim,query_temp("weapon", me));
        COMBAT_D->do_attack(target,victim,query_temp("weapon", target));
        COMBAT_D->do_attack(me,victim,query_temp("weapon", me));
        COMBAT_D->do_attack(target,victim,query_temp("weapon", target));

        addn_temp("apply/damage", -skill, me);
        addn("neili", -150, me);
        addn_temp("apply/damage", -skill, target);
        addn("neili", -150, target);


        me->start_call_out( (: call_other, __FILE__, "check_fight", me, target, victim :), 1);

        return 1;
}

void check_fight(object me, object target, object victim)
{
        object weapon;
        if( !query_temp("hebi", me) || !query_temp("hebi", target))return ;

        if( !living(victim) || !present(query("id",victim), environment(me)) || 
                query("qi", victim) <= 50 && me->is_fighting(victim) && target->is_fighting(victim) )
        {
                BUFF_D->debuff(me, "quanzhen_hebi", 1);
                BUFF_D->debuff(target, "yunv_hebi", 1);
                message_vision(HIY"$N與$n個自收招，相視一笑。\n\n"NOR, me, target);
                                return;
        }
        else if( (!present(query("id", victim),environment(me)) && target->is_fighting(victim) )
        || (!present(query("id", target),environment(me)) && me->is_fighting(victim))){
                BUFF_D->debuff(me, "quanzhen_hebi", 1);
                BUFF_D->debuff(target, "yunv_hebi", 1);
                tell_object(me, HIR"雙劍合璧已然瓦解！\n"NOR);
                tell_object(target, HIR"雙劍合璧已然瓦解！\n"NOR);
                tell_object(victim, HIY"雙劍合璧已然瓦解，壓力頓減，你不由然地鬆了一口氣。\n"NOR);
                                return;
        }
        else if( !present(query("id", target),environment(me) )
        || !target->is_fighting() || !me->is_fighting() || !living(target)
        || !living(me) || target->is_ghost() || me->is_ghost() ) {
                BUFF_D->debuff(me, "quanzhen_hebi", 1);
                BUFF_D->debuff(target, "yunv_hebi", 1);
                tell_object(me, HIR"雙劍合璧已然瓦解！\n"NOR);
                tell_object(target, HIR"雙劍合璧已然瓦解！\n"NOR);
                tell_object(victim, HIY"雙劍合璧已然瓦解，壓力頓減，你不由然地鬆了一口氣。\n"NOR);
                                return;
        }
        else if( !objectp(weapon=query_temp("weapon", me) )
        || query("skill_type", weapon) != "sword"){
                BUFF_D->debuff(me, "quanzhen_hebi", 1);
                BUFF_D->debuff(target, "yunv_hebi", 1);
                tell_object(me, HIR"雙劍合璧已然瓦解！\n"NOR);
                tell_object(target, HIR"雙劍合璧已然瓦解！\n"NOR);
                tell_object(victim, HIY"雙劍合璧已然瓦解，壓力頓減，你不由然地鬆了一口氣。\n"NOR);
                                return;
        }
        else if( !objectp(weapon=query_temp("weapon", target) )
        || query("skill_type", weapon) != "sword"){
                BUFF_D->debuff(me, "quanzhen_hebi", 1);
                BUFF_D->debuff(target, "yunv_hebi", 1);
                tell_object(me, HIR"雙劍合璧已然瓦解！\n"NOR);
                tell_object(target, HIR"雙劍合璧已然瓦解！\n"NOR);
                tell_object(victim, HIY"雙劍合璧已然瓦解，壓力頓減，你不由然地鬆了一口氣。\n"NOR);
                                return;
        }
        else if( me->query_skill_mapped("sword") != "quanzhen-jian")
        {
                BUFF_D->debuff(me, "quanzhen_hebi", 1);
                BUFF_D->debuff(target, "yunv_hebi", 1);
                message_vision(HIR"$N"HIR"突然劍招一轉，不再使用全真劍法，雙劍合璧頃刻瓦解。\n"NOR,me);
                return;
        }
        else if( target->query_skill_mapped("sword") != "yunv-jian")
        {
                BUFF_D->debuff(me, "quanzhen_hebi", 1);
                BUFF_D->debuff(target, "yunv_hebi", 1);
                message_vision(HIR"$N"HIR"突然劍招一轉，不再使用玉女劍法，雙劍合璧頃刻瓦解。\n"NOR,target);
                return;
        }
        call_out("check_fight", 1, me, target, victim);
}

