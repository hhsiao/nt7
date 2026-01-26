// fengzi.c

#include <ansi.h>
inherit F_SSERVER;

string name() { return "絕世風姿"; }

int perform(object me, object target)
{
        mapping buff, data;
        int level;
        string msg;
        int ap, dp;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() ||
                  !me->is_fighting(target) ||
          !living(target) || query_temp("no_living", target) )
                return notify_fail(name() + "只能對戰鬥中的對手使用。\n");

        if( (query("gender", me) != "女性" || me->query_per()<20) && !wizardp(me) )
                return notify_fail("象你這副尊容，恐怕再怎麼樣，也沒人多看你一眼的。\n");

        if( query("gender", target) != "男性" )
                return notify_fail("怎麼了？賣弄風騷也要找個正確對象吧？\n");

        if( level = me->query_skill("meiren-shanzhao", 1) < 150 )
                return notify_fail("你的美人三招不夠嫻熟，不會使用"+name()+"。\n");

        if( (int)me->query_skill("force", 1) < 160 )
                return notify_fail("你的內功不夠嫻熟，不會使用"+name()+"。\n");

        if( query("neili", me)<300 )
                return notify_fail("你的內力不足，恐怕沒法擺什麼風姿了。\n");

        if( BUFF_D->check_buff(target, "mrsz_fengzi") )
                return notify_fail("他已經對你很傾倒了，你還浪費什麼表情？\n");

        addn("neili", -200, me);
        me->start_busy(1);
        ap = attack_power(me, "strike");
        dp = defense_power(target, "force");

        ap = ap + ap * me->query_per()/25;
        if (ap / 2 + random(ap) > dp)
        {
                msg = HIC"激鬥中，卻見$N"HIC"忙中不亂，衝著$n"HIC"輕輕展顏露齒一笑，端的是豔若桃李、燦若明霞，容色柔媚無限，\n"
                        "$n心中不覺一蕩，油然升起一股親近的感覺，眼神也漸漸迷茫起來。\n" NOR;

                data = ([
                        "defense": -level,
                ]);

                buff = ([
                        "caster": me,
                        "target": target,
                        "type"  : "mrsz_fengzi",
                        "attr"  : "curse",
                        "name"  : "美人三招．絕世風姿",
                        "time"  : level/10,
                        "buff_data": data,
                        "buff_msg" : msg,
                        "disa_msg" : HIG"$N迷茫的眼神忽然一亮，心頭猛地一震，忙收攏起心神來。\n" NOR,
                        "disa_type":1,
                ]);
                BUFF_D->buffup(buff);

                if( !target->is_busy() )
                        target->start_busy(random(3)+1);
        }
        else
        {
                message_combatd(HIY"只見$N"HIY"衝著$n"HIY"輕輕露齒一笑，露出了牙縫中一絲沒嚥下去的"HIG"菜葉"HIY"。\n" NOR, me, target);
        }
        return 1;
}
