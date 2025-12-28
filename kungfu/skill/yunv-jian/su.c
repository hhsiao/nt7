// This program is a part of NT MudLIB
// suxing.c 素心訣

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return "素心決"; }
string *hbmsg = ({
HBMAG "\n$N" HBMAG "大喝一聲，雙手分使兩招，一起攻出。\n" NOR,
HBMAG "\n$N" HBMAG "雙手齊出，分使不同招式，令人眼花繚亂。\n" NOR,
HBMAG "\n$N" HBMAG "左右手分使兩招，毫不停滯，宛如兩人同時攻出。\n" NOR,
HBMAG "\n$N" HBMAG "左手一招，右手一招，兩招來路各異，令人難以低檔！\n" NOR,
});

int perform(object me, object target)
{
        string msg, pmsg;
        object weapon;
        int damage,ap,dp,married;
        int fmsk,delta;

        if( query("gender", me) != "女性" && wiz_level(me) < 2)
                return notify_fail("玉女素心只能是女的用！\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("素心訣只能對戰鬥中的對手使用。\n");

        if( me->query_skill_mapped("force") != "yunv-xinfa" )
                return notify_fail("你所用的並非玉女心法，無法施展素心訣！\n");

        if( me->query_skill("yunv-xinfa", 1) < 200 )
                return notify_fail("你的玉女心法火候未到，無法施展素心訣！\n");

        if( me->query_skill("yunv-jian", 1) < 200 )
                return notify_fail("你的玉女素心劍法火候未到，無法施展素心訣！\n");

        if( !(weapon=query_temp("weapon", me)) || query("skill_type", weapon) != "sword" )
                return notify_fail("你使用的兵器不對。\n");

        if( me->query_skill_mapped("sword") != "yunv-jian")
                return notify_fail("你必須激發玉女素心劍作為劍法才能夠使用素心訣。\n");

        if( query("neili", me)<1000 )
                return notify_fail("你的內力不夠使用玉女素心！\n");

        if( query("jingli", me)<500 )
                return notify_fail("你的精力不夠使用玉女素心！\n");

        msg = HIW "$N突然面色莊重，雙目清澄，手中" +query("name", weapon)+HIW+"蒙上了一層白霜，寒氣逼人！\n"NOR;
        msg+= HIW "$N騰身而起，姿態無比婀娜飄逸，揮劍向$n"NOR+HIW"直刺過去，快愈流星！\n"NOR;

        ap = attack_power(me, "sword") + me->query_skill("force");
        dp = defense_power(target, "parry") + target->query_skill("force");

        fmsk = me->query_skill("taishang-wangqing",1);
        
        if( mapp(query("family", target)) && query("family/family_name", target) == "全真教" )
                ap += ap/3;

        if( query("can_learn/yunv-xinfa/wall", me) )
                ap *= 2;
                                
        delta = ABILITY_D->check_ability(me, "ap_power-hubo"); // 門派ab, 左右互博的命中＋５％   
        if( delta ) ap += ap*delta/100;
                
        if (ap/2 + random(ap) > dp || !living(target))
        {
                damage = damage_power(me, "sword");
                damage+= query("jiali", me);
                damage+= me->query_all_buff("damage");
                damage+= damage / 300 * me->query_str();
                damage += damage/100 * (fmsk/100)* 5;
                
                if( query("can_learn/yunv-xinfa/wall", me) ) damage *= 3;
                //判斷結婚次數和發生性行為的次數
                if( !mapp(query("couple", me)))married = 1;
                else married = query("couple/married", me);
                if( mapp(query("sex", me))) married += query("sex/times", me);
                damage -= (damage/5) * (married - 1);
                if (damage < 10) damage = 10;
                
                if(BUFF_D->check_buff(me, "ynxf_wang"))
                {
                    msg+= HIW "$N" HIW "驀然回首，憂鬱眼神淡如清水，完全不將外界事物放在心上，\n"
                          HIW "劍招突變，一會兒，情意綿綿，一會兒卻捨命相拼，意欲尋死，\n"
                          HIW "一招一式若神來之筆，拿捏的異常準確！\n" NOR;
                          
                    damage*= 2;
                }           
                message_combatd(msg, me, target);

                pmsg=HIW"只聽$n一聲慘呼，已然給$N的"+NOR+query("name", weapon)+HIR+
                      "重重的刺中，渾身上下凝結上一層白色冰霜，冷的瑟瑟發抖！\n"NOR;
                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 200+fmsk/5, pmsg);
                
                if (me->query_skill("zuoyou-hubo",1) > 500 
                && me->query_family()=="古墓派"&&random(3)
                && (query("int", me)<25 || query("int", me)>39)
                && (!me->query_skill("count",1) || query("special_skill/capture", me))
                && living(target))
                {               
                    msg += hbmsg[random(sizeof(hbmsg))];
                    if( me->query_skill("quanzhen-jian",1) > me->query_skill("yunv-jian",1)-100)
                    {
                        msg += HIG"$N"HIG"突然間雙劍一交，"HIW"玉女劍法"HIG"與"HIC"全真劍法"HIG"分手使出，攻守驟然大增！\n";
                        damage*= 2;
                     }
                    msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 200+fmsk/5,pmsg);                      
                }
                     
                if (!target->is_busy())
                    target->start_busy(1+random(2));
                me->start_busy(2+random(3));
    
        } else
        {
                msg = HIY "$n見狀大驚失色，雙足點地，抽身急退，堪堪避過$N的這記素心訣，已是大汗淋漓。\n"NOR;
                me->start_busy(2+random(4));
        }
        message_combatd(msg, me, target);
        return 1;
}

