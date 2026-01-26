// wang.c 玉女忘情心訣

#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill, i;

        if (! target || target == me)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("只能在戰鬥中才能體會「忘情」。\n");


        if( query("gender", me) == "男性" )
                return notify_fail("女兒家的心事你怎能明白？\n");


        if( query("neili", me)<200 )
                return notify_fail("你的真氣不夠。\n");

        if( BUFF_D->check_buff(me, "ynxf_wang") )
                return notify_fail("你已經進入「"HIW"忘情"NOR"」的境界了。\n");

        if (me->query_skill("yunv-xinfa",1) < 200)

                return notify_fail("你的玉女心法還不夠精熟。\n");

        if (me->query_skill_mapped("sword") != "yunv-jian")
                return notify_fail("你沒有激發玉女劍法!\n");

        if( !query_temp("weapon", me) ||
            query("skill_type", query_temp("weapon",  me)) != "sword" )
                return notify_fail("你使用的兵器不對!\n");

        skill = me->query_skill("force");
        i = skill / 50 + 1;
        if (i > 2)
        {
                msg = HIW "$N" HIW "驀然回首，憂鬱眼神淡如清水，完全不將外界事物放在心上，\n"
                        HIW "劍招突變，一會兒，情意綿綿，一會兒卻捨命相拼，意欲尋死，\n"
                        HIW "一招一式若神來之筆，拿捏的異常準確！\n" NOR;
                tell_object(me, HIM "既已無緣，何需誓言，你不覺間進入忘情境界。\n");
                data = ([
                        "attack": skill * 2,
                        "damage": skill * 4,
                        "unarmed_damage": skill * 4,
                        "defense": skill * 4,
                ]);
                addn("neili", -100, me);

                buff = ([
                        "caster": me,
                        "target": me,
                        "type"  : "ynxf_wang",
                        "attr"  : "bless",
                        "name"  : "玉女心法．忘情心訣",
                        "time"  : skill,
                        "buff_data": data,
                        "buff_msg" : msg,
                        "disa_msg" : "一陣心痛，又勾起了你傷心的往事，忘情之意頓消。\n",
                ]);
                BUFF_D->buffup(buff);
                return 1;
        }
        else
        {
                msg = HIM "$N" HIM "心亂如麻，一時之間不能進入忘情境界。\n" NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);
        return 1;
}
