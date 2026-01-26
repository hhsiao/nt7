// This program is a part of NITAN MudLIB
// tuo.c
// 楊過決戰金輪法王時所施展的決定勝負的一招。

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
string name() { return HIM "拖泥帶水" NOR; }

int perform(object me, object target)
{
        mapping buff;
        int damage;
        string msg;
        int ap, dp;
        string couple;
        object cob;
        int adp=0;
        int delta;
        int time;
        int fmsk,ngxy,flagremote;
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能對戰鬥中的對手使用。\n");

        if( query_temp("weapon", me) || query_temp("secondary_weapon", me) )
                return notify_fail(name() + "只能空手施展。\n");

        if( query("static/marry", me)>1 )
                return notify_fail("你感情早已不純，哪裡還能領略到那種黯然銷魂的感覺？\n");

        if ((int)me->query_skill("force") < 250)
                return notify_fail("你的內功火候不夠，使不出" + name() + "。\n");

        if ((int)me->query_skill("sad-strike", 1) < 180)
                return notify_fail("你的黯然銷魂掌不夠熟練，不會使用" + name() + "。\n");

        if( query("neili", me)<500 )
                return notify_fail("你的真氣不夠，無法使用" + name() + "。\n");

        if (me->query_skill_mapped("unarmed") != "sad-strike")
                return notify_fail("你沒有激發黯然銷魂掌，無法使用" + name() + "。\n");

/*
        if( !stringp(couple=query("couple/couple_id", me)) )
                return notify_fail("你沒有妻子，體會不到這種萬念俱灰的感覺。\n");
*/
        /*
        if (! objectp(cob = find_player(couple)))
                return notify_fail("老婆不在啊，苦悶向誰發？\n");
        */
        if( userp(me) )
        {
            if( (time = BUFF_D->get_buff_overtime(me, "arxhz_tuo")) > 0 )
              return notify_fail(MAG"你剛剛施展完拖泥帶水，現在心情沒有那麼鬱悶了，還需等待"+time+"秒。\n"NOR);
        }

        if (! living(target))
                return notify_fail("對方都已經這樣了，用不著這麼費力吧？\n");

        fmsk = me->query_skill("taishang-wangqing",1);
        ngxy = me->query_skill("force-cognize",1);
        ap = attack_power(me, "unarmed") + me->query_skill("force");
        dp = defense_power(target, "parry") + target->query_skill("force");

        delta = ABILITY_D->check_ability(me, "ap_power-arxhz-tuo"); // 門派ab
        if( delta ) ap += ap*delta/100;

        me->start_busy(2);

        if (random(3) == 1 && query("max_neili", me) > 50000)
        {
            msg = HIR "$N" HIR "心下萬念俱灰，悽然向妻子"
                      HIR "望了一眼，暗道：“別了！你自己保重。”\n"
                      "當下失魂落魄，隨手一招，恰好使出了黯然銷魂掌中"
                      "的「拖泥帶水」。\n" NOR;
            ap += ap  / 5;
            if( query("can_perform/surge-force/new", me )
            && me->query_skill_mapped("force") == "surge-force"
            && fmsk > 500)
            ap *= 2;
        } else
        {
            msg = HIM "只見$N" HIM "沒精打采的揮袖卷出，面無表情，隨意拍出一掌，正是"
                      "黯然銷魂掌中的「拖泥帶水」。\n"NOR;
        }

        damage = damage_power(me, "unarmed");
        damage+= query("jiali", me);
        damage+= me->query_all_buff("unarmed_damage");
        damage+= damage / 300 * me->query_str();
        damage*= 2;

        flagremote = UNARMED_ATTACK;
        if(ngxy > 8000 & fmsk > 1000) flagremote = SPECIAL_ATTACK;
        if(ngxy > 15000 & fmsk > 1800) flagremote = REMOTE_ATTACK;

        delta = ABILITY_D->check_ability(me, "da_power-arxhz-tuo"); // 門派ab
        if( delta ) damage += damage*delta/100;
        if(fmsk > 500) damage += damage /1000 * fmsk;

        if (query("can_perform/surge-force/new", me)
        && me->query_skill_mapped("force") == "surge-force"
        && (random(3) > 1 || query("eff_qi", me)*100/query("max_qi", me) < 20 )
                && fmsk > 500)
        {
                msg += HIC "$N"HIC"仰天長嘯，氣勢如山洪爆發，丹田內力迅速遊遍全身！\n";
//              ap += ap / 3;
                damage += damage * 10;
                adp = 180;
        }
        if (ap / 2 + random(ap) > dp)
        {
                addn("neili", -30000, me);
                msg += COMBAT_D->do_damage(me, target, flagremote, damage, 200+fmsk/10+adp,
                                           HIR "只聽$n" HIR "一聲悶哼，“噗”的一"
                                           "聲，這一掌正好擊在$p" HIR "肩頭。 \n"
                                           NOR);
        } else
        {
                addn("neili", -100, me);
                msg += HIC "可是$p" HIC "小心應付、奮力招架，擋開了這一招。\n"
                       NOR;
        }
        message_combatd(msg, me, target);
        time  = 40;
        time -= ABILITY_D->check_ability(me, "cd-arxhz-tuo"); // ab門派減cd
        time -= ABILITY_D->check_ability(me, "reduce_cd", 2); // talent減cd
        if( wiz_level(me) > 2) time = 2;
        buff =
        ([
                "caster" : me,
                "target" : me,
                "type"   : "cooldown",
                "type2"  : "arxhz_tuo",
                "attr"   : "curse",
                "name"   : "黯然銷魂掌．拖泥帶水",
                "time"   : time,
                "buff_msg" : "黯然銷魂掌消耗心神太甚，還需等待"+time+"秒方可再次施展。\n",
                "disa_msg" : "",
                "disa_type": 0,
        ]);
        BUFF_D->buffup(buff);
        return 1;
}
