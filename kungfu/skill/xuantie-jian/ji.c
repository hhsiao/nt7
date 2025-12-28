#include <ansi.h>

inherit F_SSERVER;

string name() { return "千鈞一擊"; }

int perform(object me, object target)
{
        object weapon;
        int skill, skill1, fmsk;
        int myskill;
        int damageone;
        int damagesub;
        int damage;
        string msg;
        mixed ap,dp;
        int status_flag=0;
        int delta;

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("千鈞一擊只能對戰鬥中的對手使用。\n");

        if( !objectp(weapon=query_temp("weapon", me)) )
                return notify_fail("你未持武器，不能使用千鈞一擊！\n");

        if( me->query_skill("force") < 300 )
                return notify_fail("你的內功火候未到，無法施展千鈞一擊！\n");

        if( me->query_skill("sword") < 300 )
                return notify_fail("你的劍法火候未到，無法施展千鈞一擊！\n");

        if( query("max_neili", me) <= 30000 )
                return notify_fail("你的內力不夠施展千鈞一擊！\n");
                                
        if( me->query_skill_mapped("sword") != "xuantie-jian")
                return notify_fail("你必須激發玄鐵劍法作為劍法才能夠使用千鈞一擊。\n");
                                
        if( me->query_skill_mapped("force") != "surge-force")
                return notify_fail("你必須激發怒海狂濤作為內功才能夠使用千鈞一擊。\n");
                                
        if( query("neili", me) <= query("max_neili", me)/10 )
                return notify_fail("你的內力不夠施展千鈞一擊！\n");

        if( query("jingli", me) <= 1000 )
                return notify_fail("你的精力不夠施展千鈞一擊！\n");
                
        if( query_temp("xtj_ji_cd", me) && time()-query_temp("xtj_ji_cd", me) < 1 )
                return notify_fail("你上一個動作還沒有完成，不能施用外功。\n");
                
        msg=HIW"\n$N身子左斜，左手抽出揹負的"+query("name", weapon)+NOR+HIW"，順手一招「千鈞一擊」!\n\n"NOR;
        
        fmsk = me->query_skill("taishang-wangqing", 1);
        ap=attack_power(me, "sword");
        dp=defense_power(target, "force");
        damage = damage_power(me, "sword");
        damage+= query("jiali", me);
        damage+= me->query_all_buff("damage");
        damage+= damage / 300 * me->query_str();
        damage+= damage * (fmsk/100)* 5 / 100;
        damage*= 2;
        addn_temp("apply/add_damage",100,me);
        delta = ABILITY_D->check_ability(me, "ap_power-xtj-ji"); // 門派ab
        if( delta ) ap += ap*delta/100;

        delta = ABILITY_D->check_ability(me, "da_power-xtj-ji"); // 門派ab
        if( delta ) damage += damage*delta/100;
        
        if (query("can_perform/surge-force/new", me) && me->query_skill("surge-force", 1) )
        {
            ap*= 2;
            damage*= 4;
            msg+= HIY"$N"HIY"一聲長嘯，激起一陣狂風，氣浪翻翻滾滾，向兩旁散開。"
            "霎時之間，便似長風動起，氣雲聚合，天地渺然，有如海浪滔滔！\n\n";
        }

        if ( ap/2 + random(ap) > dp )
        {
                msg+=HIC"$N力道使得極猛,挺劍送出。$n"NOR+HIC"早有提防，卻萬想不到來勢竟是如此猛烈，眼見閃避不及，"
                "只聽砰的一聲猛響，登時連退了五六步，才勉強拿椿站定，登時臉如金紙。\n"NOR;
                if(random(me->query_all_buff("fatal_blow")) > 30)
                {
                    damage*= 4;
                    msg+= HIY"$N"HIY"觸發致命一擊，對$n"HIY"造成「400%」的傷害！\n";
                }        
                target->receive_damage("qi", damage,  me);
                target->receive_wound("qi", damage, me);
                set_temp("xtj_ji_cd",time(),me);
                addn("neili", -query("max_neili", me)/20, me);
                me->start_busy(2+random(2));
                status_flag=1;
        }

        else if( query("int", me)>random(query("int", target)*2) )
        {
                msg+=HIC"$N一劍擊出，右手長袖順勢拂去，$n"NOR+HIC"頃刻間只感五臟六腑都似翻轉了，站在當地，既不敢運氣，\n"
                        "也不敢移動半步，便如僵了一般。\n"NOR;
                if (! target->is_busy())
                   target->start_busy(5+random(4));
                me->start_busy(2+random(2));
                status_flag=1;
        }
        else if (query("str", me)>random(query("str", target)*2) )
        {
                msg+=HIC"$N只覺對方衝撞而來的勁力綿綿不絕，越來越強,運出所有內力振臂一擊。\n" NOR;
                addn("neili", -query("max_neili", me)/40, me);
                addn("neili", -query("max_neili", target)/20, target);
                me->start_busy(1+random(2));
                if (! target->is_busy())
                    target->start_busy(1+random(2));
                status_flag=1;
        }
        else
        {
                msg += HIG"$n凌空飛躍，身形疾閃，使出本門輕功，身子往回輕輕一側，$N的發招數盡數落空。\n"NOR;
                me->start_busy(2+random(2));
        }
        addn("neili", -200, me);
        addn_temp("apply/add_damage",-100,me);
        
        if(query("neili", me) < 0) set("neili",0,me);
        if(query("neili", target) < 0) set("neili",0,target);
        
        message_combatd(sort_msg(msg)+"\n", me, target);
        if (status_flag==1) COMBAT_D->report_status(target);
        return 1;
}

