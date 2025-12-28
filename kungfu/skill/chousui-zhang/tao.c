#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return HIG "碧焰滔天" NOR; }
string attack(object me, object target, int damage);

int perform(object me, object target)
{
        object du;
        int damage;
        string msg, msg1;
        int ap, dp, lvl, fmsk;
        int delta;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("你只能對戰鬥中的對手施展" + name() + "。\n");

        if ((int)me->query_skill("chousui-zhang", 1) < 220)
                return notify_fail("你的抽髓掌火候不夠。\n");

        if ((int)me->query_skill("poison", 1) < 250)
                return notify_fail("你的基本毒技火候不夠。\n");

        if ((int)me->query_skill("huagong-dafa", 1) < 220)
                return notify_fail("你的化功大法火候不夠。\n");

        if( query("max_neili", me)<3000 )
                return notify_fail("你的內力修為不足，無法用內力施展" + name() + "。\n");

        if( query("neili", me)<3000 )
                return notify_fail("你現在內息不足，無法用內力施展" + name() + "。\n");

        if (me->query_skill_prepared("strike") != "chousui-zhang")
                return notify_fail("你還沒有準備抽髓掌，無法施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("對方都已經這樣了，用不著這麼費力吧？\n");

        msg = HIR "只見$N" HIR "雙目血紅，頭髮散亂，猛地仰天發出一聲悲嘯。\n\n"
              "$N" HIR "把心一橫，在自己舌尖狠命一咬，將畢生功力盡"
              "數噴出，頓時只見空氣中血霧瀰漫，腥臭無比，隨即又\n"
              "聽$N" HIR "骨骼“噼裡啪啦”一陣爆響，雙臂順著噴出的"
              "血柱一推，剎那間一座丈來高的奇毒火牆拔地而起，帶\n"
              "著排山倒海之勢向$n" HIR "湧去！\n" NOR;
        me->start_busy(2 + random(2));
        addn("neili", -1000, me);

        lvl = me->query_skill("chousui-zhang", 1);
        fmsk = me->query_skill("bingcan-gong", 1);
        damage = damage_power(me, "strike");
        damage+= query("jiali", me);
        damage+= me->query_all_buff("unarmed_damage");
        damage+= damage / 300 * me->query_str();

        delta = ABILITY_D->check_ability(me, "da_power-csz-tao"); 
        if( delta ) damage += damage*delta/100;

        ap = attack_power(me, "strike") +
             me->query_skill("poison", 1);
        dp = defense_power(target, "dodge") +
             target->query_skill("force", 1)/2;
        
        delta = ABILITY_D->check_ability(me, "ap_power-csz-tao"); // 門派ab
        if( delta ) ap += ap*delta/100;
        
        if (ap + random(ap) < dp)
        {
                msg += CYN "$n" CYN "見勢不妙，急忙騰挪身形，避開了$N" CYN "的攻擊。\n" NOR;
                // me->addn("max_neili", -random(50));
                if (! target->is_busy())
                        target->start_busy(3);
        } else
        {
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 90+fmsk/10, (: attack,me,target,damage :));

                target->affect_by("fire_poison",
                               (["level":query("jiali", me)*6+random(query("jiali", me)*4),
                                  "id":query("id", me),
                                  "duration" : lvl / 20 + random(lvl) ]));
                if (! target->is_busy())
                        target->start_busy(5);
        }

        message_vision(msg, me, target);

        return 1;
}
string attack(object me, object target, int damage)
{
        mapping buff, data;
        string msg;

        msg = HIR "$n" HIR "見滔天熱浪撲面湧來，只覺眼前一片通紅，"
                       "已被捲入火浪，毒焰席捲全身，連骨頭都要烤焦一般。\n" NOR;

        if( random(2) != 1 ) return msg;
        
        data = ([
                "avoid_poison": -90,

        ]);
        buff = ([
                "caster": me,
                "target": target,
                "type"  : "chousui-zhang_tao",
                "attr"  : "curse",
                "name"  : "碧焰滔天·毒火攻心",
                "time"  : 200,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : HIG "你只覺得心胸清朗，靈臺空明。\n" NOR,
                        
        ]);
        BUFF_D->buffup(buff);

        msg += RED "$n" RED "感到五臟六腑如同烈焰灼燒一般，痛苦萬分。\n" NOR;

        return msg;
}

