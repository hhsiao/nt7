// 太極劍意

#include <ansi.h>
#include <combat.h>

string name() { return HIM "太極劍意" NOR; }

inherit F_SSERVER;

string attack1(object me, object target, int damage);
string attack2(object me, object target, int damage);

int perform(object me, object target)
{
        mapping buff, data;
        int damage;
        string msg;
        object weapon;
        int ap, dp, fp;
        int xy, ngxy, taoism, tjss;
        int time;
        int delta;
         int flagremote;

        if( userp(me) && !query("yuanshen", me) )
                return notify_fail("你尚未悟道，無法使用太極劍意！\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能在戰鬥中對對手使用。\n");


        if( me->is_busy() )
                return notify_fail("你正忙著呢。\n");

        if( !objectp(weapon=query_temp("weapon", me)) ||
            query("skill_type", weapon) != "sword" )
                return notify_fail("你使用的武器不對！\n");

        if ((int)me->query_skill("taiji-jian", 1) < 1000)
                return notify_fail("你太極劍法不夠嫻熟，無法施展" + name() + "。\n");

        if( query("neili", me)<2000 )
                return notify_fail("你現在真氣不夠，無法施展" + name() + "！\n");

        if (me->query_skill_mapped("sword") != "taiji-jian")
                return notify_fail("你沒有激發太極劍法，無法使用" + name() + "。\n");
        
        if( userp(me) ) 
        {
                if( (time = BUFF_D->get_buff_overtime(me, "tjj_jian")) > 0 )
                        return notify_fail(MAG"太極劍意消耗心神太甚，還需等待"+time+"秒。\n"NOR);
        }
        
        if (! living(target))
               return notify_fail("對方都已經這樣了，用不著這麼費力吧？\n");

        addn("neili", -1000, me);

        ap = attack_power(me, "sword");
        dp = defense_power(target, "dodge");
        fp = defense_power(target, "parry");


        xy = me->query_skill("tianwei-zhengqi", 1);
        ngxy = me->query_skill("force-cognize", 1);
        taoism = me->query_skill("taoism", 1);
                tjss = me->query_skill("taiji-shengong", 1);
                
        ap = ap + ap*(xy/100<10?10:xy/100)/10;
        if(target->is_bad())
                ap += ap/10;
                
          damage = damage_power(me, "sword");
          damage = damage_power(me, "force");
          damage+= me->query_all_buff("damage");
          damage = damage + damage*(xy/50<10?10:xy/50)/10;
          damage = damage /2 *(query("str",me)+query("dex",me)) ;
        
        delta = ABILITY_D->check_ability(me, "ap_power-tjj-jian"); // 門派ab
        if( delta ) ap += ap*delta/100;
        
        delta = ABILITY_D->check_ability(me, "da_power-tjj-jian"); // 門派ab
        if( delta ) damage += damage*delta/100;
        
        //target->start_busy(10);

                if(taoism > 1200 && ngxy > 5000 && !userp(target)) 
                damage *= taoism/1200 + ngxy/1000;
        if(tjss > 10000 & taoism > 10000)
          {
             if(random(100) < tjss/120 || random(100) < 80)
             flagremote = 1;
                   }
                 if(tjss > 8000) damage += damage/8;
         if(tjss > 12000) damage += damage/7;
         if(tjss > 16000) damage += damage/6;
                 
        message_combatd(sort_msg(HIY "\n$N" HIY "身形一轉，手中" + weapon->name() + HIY "輕靈而出，猶如碧"
                     "波盪漾，蜿蜒起伏，形態飄逸瀟灑之極，頗具" HIC "太極" HIY "之意" HIY "……\n" NOR), me);

        msg = HIM "$N" HIM "將內力灌輸於劍上，呼的一劍抖出，空氣幾欲凝固。\n" NOR;
        if (ap*2/3 + random(ap / 2) < dp)
                msg += CYN "$n" CYN "眼明手快，斜身閃開。\n" NOR;
        else
        {
                        
                msg += COMBAT_D->do_damage(me, target, (flagremote ? SPECIAL_ATTACK : WEAPON_ATTACK), damage, 100 + (xy / 2 + random(xy / 2)>500?500:xy / 2 + random(xy / 2)),
                                           (: attack1, me, target, damage :));
        }

        msg += HIM "\n$N" HIM "輕搖" + weapon->name() + HIM "，霎時，劍氣縱橫，流光乍現，令人目不暇接。\n" NOR;
        if (ap*2/3 + random(ap / 2) < fp)

                msg += CYN "$n" CYN "倒吸一口涼氣，飛身一跳，狼狽地躲過這招。\n" NOR;
        else
        {
                msg += COMBAT_D->do_damage(me, target, (flagremote ? REMOTE_ATTACK : WEAPON_ATTACK), damage, 100 + (xy / 2 + random(xy / 2)>500?500:xy / 2 + random(xy / 2)),
                                           (: attack2, me, target, damage :));
        }

        me->start_busy(2 + random(3));
        message_combatd(msg, me, target);
        
        time = 40;
        time -= ABILITY_D->check_ability(me, "cd-tjj-jian"); // ab門派減cd
        time -= ABILITY_D->check_ability(me, "reduce_cd", 2); // talent減cd  
                
        buff =  
        ([
                "caster" : me,
                "target" : me,
                "type"   : "cooldown",
                "type2"  : "tjj_jian",
                "attr"   : "curse",
                "name"   : "太極劍法·太極劍意",
                "time"   : time,
                "buff_msg" : "太極劍意消耗心神太甚，還需等待"+time+"秒方可再次施展。\n",
                "disa_msg" : "",
                "disa_type": 0,
        ]);
        BUFF_D->buffup(buff);
        return 1;
}


string attack1(object me, object target, int damage)
{
        string msg;

        msg = HIR "$N" HIR "劍法飄逸無比，令$n" HIR "毫無反應，"
              "竟呆立當場，不守不攻。\n" NOR;

        // if( random(2) != 1 ) return msg;
        //if( target->query_condition("no_perform") ) return msg;

        target->apply_condition("no_perform", 5);

        msg += WHT "$n" WHT "感到氣脈受損，全身力道竟似渙散了一般，全然無法控制。\n" NOR;

        return msg;
}

string attack2(object me, object target, int damage)
{
        mapping buff, data;
        string msg;

        msg = HIR "$N" HIR "劍法越發凌厲，將$n" HIR "逼得接連後退，"
              "劍光一閃，令$n" HIR "再也無從躲避。\n" NOR;

        if( random(2) != 1 ) return msg;
        
        data = ([
                "avoid_busy": -90,
                "reduce_busy": -36,
                "avoid_weak": -90,
                "avoid_locked": -90,
        ]);
        buff = ([
                "caster": me,
                "target": target,
                "type"  : "tjj_fengyin",
                "attr"  : "curse",
                "name"  : "太極劍法·封印",
                "time"  : 30,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : HIR "你的忽視虛弱，忽視忙亂、忽視絕招冷凍能力終於解除封印。\n" NOR,
                        
        ]);
        BUFF_D->buffup(buff);

        msg += WHT "$n" WHT "感到自身的忽視虛弱，忽視忙亂、忽視絕招冷凍能力被封印。\n" NOR;

        return msg;
}

