#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return "天脈神劍"; }
string *sname = ({"少衝劍","少澤劍","中衝劍","關衝劍","商陽劍","少商劍",});
string *color = ({HIR,HIG,HIY,HIB,HIM,HIC,});
string *xue_name = ({
"勞宮穴", "膻中穴", "曲池穴", "關元穴", "曲骨穴", "中極穴", "承漿穴", "天突穴", "百會穴",
"幽門穴", "章門穴", "大橫穴", "紫宮穴", "冷淵穴", "天井穴", "極泉穴", "清靈穴", "至陽穴", });

int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int damage, skill, fmsk, kurong, ngxy, jingluo;
        int n;
        int time;
        int delta;
        mapping buff;

        if (! target) target = offensive_target(me);

        if( userp(me) && !query("yuanshen", me) )
                return notify_fail("你還沒有悟道，不能施展天脈神劍。\n");

/*
        if( query("family/family_name", me) != "段氏皇族"
         && member_array("段氏皇族", query("reborn/fams", me)) == -1 )
                return notify_fail("你所使用的外功中沒有這種功能。\n");
*/

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能對戰鬥中的對手使用。\n");

        if( me->is_busy() )
                return notify_fail("你正忙著呢。\n");

        if (me->query_skill_prepared("finger") != "six-finger")
                return notify_fail("你沒有準備使用六脈神劍，無法施展" + name() + "。\n");

        skill = me->query_skill("six-finger", 1);
        fmsk = me->query_skill("qimai-liuzhuan", 1);
        kurong = me->query_skill("kurong-changong", 1);
        ngxy = me->query_skill("force-cognize", 1);
        jingluo = me->query_skill("jingluo-xue", 1);
        if (skill < 800)
                return notify_fail("你的六脈神劍修為有限，無法使用" + name() + "！\n");

        if (me->query_skill("force", 1) < 1000)
                return notify_fail("你的內功火候不夠，難以施展" + name() + "！\n");

        if( query("max_neili", me)<120000 )
                return notify_fail("你的內力修為不夠,無法施展" + name() + "！\n");

        if( query("neili", me)<100000 )
                return notify_fail("你的真氣不夠，現在無法施展" + name() + "！\n");

        if( query_temp("weapon", me) )
                return notify_fail("你必須是空手才能施展" + name() + "！\n");

        if( userp(me) )
        {
                if( (time = BUFF_D->get_buff_overtime(me, "lmsj_tian")) > 0 )
                        return notify_fail(MAG"天脈神劍消耗心神太甚，還需等待"+time+"秒。\n"NOR);
        }

        if (! living(target))
                return notify_fail("對方都已經這樣了，用不著這麼費力吧？\n");

        msg = HIC"               --------天--------\n";
        msg+= HIG"                 ------脈------\n";
        msg+= HIY"                   ----神----\n";
        msg+= HIR"                     --劍--\n\n";
        message_combatd(msg, me, target);
        msg = HIC "$N" HIC "一聲清嘯，右手五指紛彈，頓覺六脈劍譜已湧上心頭，此起"
              "彼伏、連綿不絕。\n霎時劍氣如奔，連綿無盡的萬道劍氣豁然貫向$n" HIM
              "！\n" NOR;
        msg+=color[random(sizeof(color))]+ "┏------------┓\n";
        msg+= "┃   "+sname[random(sizeof(sname))]+"   ┃\n";
        msg+= "┗------------┛\n";
        ap = attack_power(me, "finger");
        dp = defense_power(target, "force");

        // 提高20%
        ap = ap + ap / 5 + me->query_skill("martial-cognize", 1) + me->query_skill("jingluo-xue", 1);
        ap *= 2;
       //▁▂▃▄▅▆▇█▇█
        delta = ABILITY_D->check_ability(me, "ap_power-lmsj-tian"); // 門派ab
        if( delta ) ap += ap*delta/100;

        damage = damage_power(me, "finger") + me->query_skill("martial-cognize", 1) + me->query_skill("jingluo-xue", 1);
        damage+= query("jiali", me);
        damage+= me->query_all_buff("unarmed_damage");
        damage+= damage / 300 * me->query_str();
        damage*= 2;
        delta = ABILITY_D->check_ability(me, "da_power-lmsj-tian"); // 門派ab
        if( delta ) damage += damage*delta/100;
        if( (n = fmsk / 100) >= 1 )
        damage += damage*n*15/100;

        // 有20%幾率施展無BUSY
        if (random(5) != 1) me->start_busy(2 + random(3));

        if ((int)target->query_skill("martial-cognize", 1) >= 2000 && target->query_skill("jingluo-xue", 1) >= 200
            && target->query_skill("dodge", 1) >= me->query_skill("six-finger", 1)
            && random (30) == 1 )
        {
                addn("neili", -2000, me);
                msg += HIY "但見$n" HIY "會心一笑，輕拂衣袖，輕易的躲過這一招！\n"NOR;
        } else
        if (ap + random(ap) > dp)
        {
                if( (n = fmsk / 100) >= 1 )
                msg += HIM"$N"HIM"運用氣脈流轉的輔助，使得天脈神劍傷害更強。\n"NOR;
                addn("neili", -query("max_neili", me)/40, me);
                msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 300 + random(200),
                                           RED "只聽$n" RED "一聲慘叫，萬道劍氣已"
                                           "透體而過，傷口處鮮血頓時狂湧，痛苦難當！\n" NOR);
                if(me->query_skill("sun-finger",1) >= skill /4*3 && random(fmsk) > 200 && random(jingluo)>200
                && random(me->query_skill("finger")) > target->query_skill("dodge") / 3)
                {
                    msg+=  HIB "$N" HIB "凝聚一陽指訣功力，陡然點出一指，變化多端，巧逼$n"HIB"諸處大穴。\n" NOR;
                    msg+=  "$n"HIB"一不留神，"+NOR+HBMAG+HIW+xue_name[random(sizeof(xue_name))]+NOR+HIB"被$N點中，登時手忙腳亂！\n"NOR;
                    if( !target->is_busy() ) target->start_busy(8);
                }

        } else
        {
                addn("neili", -400, me);
                msg += CYN "$n" CYN "見$N" CYN "來勢洶湧，不敢輕易"
                       "招架，急忙提氣躍開。\n" NOR;
        }

        if(skill > 5000 && random(kurong) > 2500)
        {
            msg += HIG "\n$N" HIG "一聲清嘯，左手五指紛彈，頓覺六脈劍譜已湧上心頭，此起"
                  "彼伏、連綿不絕。\n霎時劍氣如奔，連綿無盡的萬道劍氣豁然貫向$n" HIG
                  "！\n" NOR;
            msg+=color[random(sizeof(color))]+ "┏------------┓\n";
            msg+= "┃   "+sname[random(sizeof(sname))]+"   ┃\n";
            msg+= "┗------------┛\n";

            // 第二招
            if ((int)target->query_skill("martial-cognize", 1) >= 2000
                && target->query_skill("dodge", 1) >= me->query_skill("six-finger", 1)
                && random (30) == 1 )
            {
                    addn("neili", -600, me);
                    msg += HIY "但見$n" HIY "會心一笑，輕拂衣袖，輕易的躲過這一招！\n"NOR;
            } else
            if (ap + random(ap) > dp)
            {
                    if( (n = fmsk / 100) >= 1 )
                    msg += HIM"$N"HIM"運用氣脈流轉的輔助，使得天脈神劍傷害更強。\n"NOR;
                    addn("neili", -query("max_neili", me)/40, me);
                    msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 300 + random(200),
                                               RED "只聽$n" RED "一聲慘叫，萬道劍氣已"
                                               "透體而過，傷口處鮮血頓時狂湧，痛苦難當！\n" NOR);
                if(me->query_skill("sun-finger",1) >= skill /4*3 && random(fmsk) > 200 && random(jingluo)>200
                && random(me->query_skill("finger")) > target->query_skill("parry") / 3)
                {
                    msg+=  HIB "$N" HIB "凝聚一陽指訣功力，陡然點出一指，變化多端，巧逼$n"HIB"諸處大穴。\n" NOR;
                    msg+=  "$n"HIB"一不留神，"+NOR+HBMAG+HIW+xue_name[random(sizeof(xue_name))]+NOR+HIB"被$N點中，登時身子軟了下去！\n"NOR;
                    target->set_weak(5);
                }
            } else
            {
                    addn("neili", -400, me);
                    if (random(5) != 1)me->start_busy(5);
                    msg += CYN "$n" CYN "見$N" CYN "來勢洶湧，不敢輕易"
                           "招架，急忙提氣躍開。\n" NOR;
            }
        }
        if(skill > 10000 && random(kurong) > 5000)
        {
            msg += HIY "\n$N" HIY "一聲清嘯，左手五指紛彈，頓覺六脈劍譜已湧上心頭，此起"
                  "彼伏、連綿不絕。\n霎時劍氣如奔，連綿無盡的萬道劍氣豁然貫向$n" HIG
                  "！\n" NOR;
            msg+=color[random(sizeof(color))]+ "┏------------┓\n";
            msg+= "┃   "+sname[random(sizeof(sname))]+"   ┃\n";
            msg+= "┗------------┛\n";

            // 第三招
            if ((int)target->query_skill("martial-cognize", 1) >= 2000
                && target->query_skill("dodge", 1) >= me->query_skill("six-finger", 1)
                && random (30) == 1 )
            {
                    addn("neili", -600, me);
                    msg += HIY "但見$n" HIY "會心一笑，輕拂衣袖，輕易的躲過這一招！\n"NOR;
            } else
            if (ap + random(ap) > dp)
            {
                    if( (n = fmsk / 100) >= 1 )
                    msg += HIM"$N"HIM"運用氣脈流轉的輔助，使得天脈神劍傷害更強。\n"NOR;
                    addn("neili", -query("max_neili", me)/40, me);
                    msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 300 + random(200),
                                               RED "只聽$n" RED "一聲慘叫，萬道劍氣已"
                                               "透體而過，傷口處鮮血頓時狂湧，痛苦難當！\n" NOR);
                if(me->query_skill("sun-finger",1) >= skill /4*3
                && random(fmsk) > 200
                && random(jingluo)>200
                && random(me->query_skill("finger")) > target->query_skill("force") / 2)
                {
                    msg+=  HIB "$N" HIB "凝聚一陽指訣功力，陡然點出一指，變化多端，巧逼$n"HIB"諸處大穴。\n" NOR;
                    msg+=  "$n"HIB"一不留神，"+NOR+HBMAG+HIW+xue_name[random(sizeof(xue_name))]+NOR+HIB"被$N點中，真氣源源而洩！\n"NOR;
                    set("neili",0,target);
                }
            } else
            {
                    addn("neili", -400, me);
                    if (random(5) != 1)me->start_busy(5);
                    msg += CYN "$n" CYN "見$N" CYN "來勢洶湧，不敢輕易"
                           "招架，急忙提氣躍開。\n" NOR;
            }
        }


        if( query("neili", me)< 0) set("neili",0,me);
        message_combatd(msg, me, target);

        time  = 40;
        time -= ABILITY_D->check_ability(me, "cd-lmsj-tian"); // ab門派減cd
        time -= ABILITY_D->check_ability(me, "reduce_cd", 2); // talent減cd
        if( wiz_level(me) > 2) time = 2;
        buff =
        ([
                "caster" : me,

                "target" : me,
                "type"   : "cooldown",
                "type2"  : "lmsj_tian",
                "attr"   : "curse",
                "name"   : "六脈神劍·天脈神劍",
                "time"   : time,
                "buff_msg" : "天脈神劍消耗心神太甚，還需等待"+time+"秒方可再次施展。\n",
                "disa_msg" : "",
                "disa_type": 0,
        ]);
        BUFF_D->buffup(buff);

        return 1;
}
