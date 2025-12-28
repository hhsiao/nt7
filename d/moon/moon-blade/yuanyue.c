#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
object weapon;
int extra, agi,str,cor,kar,exp,tarexp,n,k,dance;
int rkee,damage,low_limit;
      if ( me->query("class")!= "bandit")
		    return notify_fail("非神教弟子不能領悟明月幾十有。\n");
if (!me->query("dingpeng/yuanyue")&& userp(me))
      return notify_fail("你還未領悟圓月魔刀要訣，看來要請高人指點才行。\n");
//if (me->query_temp("kill_other"))
//return notify_fail("你正在施展［明月幾時有］。\n");
extra = me->query_skill("moon-blade",1);
if((int) extra < 400)
return notify_fail("你的圓月刀神斬還不夠精純，不能出［明月幾時有］。\n");
k = 40;
k -= (extra - 400)/10;
if (k<=0) k=0;
if (me->query_temp("timer/yuanyue")+k>time()&&extra<600)
	return notify_fail("你的圓月刀神斬還不夠精純，不能連續出［明月幾時有］。\n");
if( !target ) target = offensive_target(me);
if( !target
|| !target->is_character()
|| !me->is_fighting(target) )
return notify_fail("［明月幾時有］只能對戰鬥中的對手使用。\n");
dance = target->query_skill("cloud-dance",1);
if (target->query("class")=="huashan") dance *= 4;
combat_message_vision(RED"$N"+NOR RED"手一揮，刀光已飛起……
"WHT"圓月落，刀光起。
縱橫大地十萬裡。
刀光寒如雪，何處聽春雨？"NOR"
"BRED HIY"彎彎的刀，彎彎的刀光，開始時宛如一彎新月，忽然間變成了一道飛虹。\n"NOR,me,target);
weapon=me->query_temp("weapon");
exp = me->query("combat_exp")/1000;
if (me->query("moonblade")) exp = exp*me->query("moonblade");
tarexp = target->query("combat_exp")/1000;
 k = me->query("str")+me->query("agi");
 if (k>1000) k = 1000;
 if ((target->query("max_kee")<extra*extra/50||(random(extra)>1500&&random(30000)<k))&&!target->query("treasure_npc"))
                if( COMBAT_D->do_magic(me,target,"wuli")==1 )
                {
						combat_message_vision(WHT"\n\n雖然$n"+NOR WHT"根本沒有看清楚，但是可以感覺到。。。"+BLINK HIW"$N"+BLINK HIW"已然出刀！\n"NOR, me, target);
                    //    me->set_temp("kill_other",1);
                        me->start_busy(4);
                        if (random(dance+extra)>extra) {
                        		combat_message_vision(HIC"
$N有如敦煌壁畫上的天女一般，提足如神山飛渡，側臉如桃花相映，旋身如飛
燕投林，這一舞，宛似舞了一座江南一處長安，一時間千變萬幻，蜃影重重；一
時間淋漓暢盡，似飄似颺。\n"NOR,target);
	message_vision(HIR "\n$N一刀竟然劈到空處！！\n" NOR , me);
	   me->delete_temp("kill_other");

        return 1;
                        }
                        target->set_temp("last_damage_from",me);
                      //  if (me->query_temp("gamehock")) {
                        	if (target->query_skill("bloodghost",1)>random(me->query_skill("moon-blade",1))&&target->query("timer/bloodghost")+3600<time()) {
        	message_vision(HIR "\n$N見情勢不妙，霎時間急運血魔神功中的『化血為身』！！\n" NOR , target);
        	 combat_message_vision(HIC "\n$N"+HIC"忽然由頂至踵分為兩片，向兩邊倒了下去！！\n" NOR , target);
        	 	message_vision(HIR "\n$N化作一灘血水，原來被打中的只是$N以血換化的假身！！\n" NOR , target);
        	 	   me->delete_temp("kill_other");
    //    me->add("bellicosity",100);
        target->set("timer/bloodghost",time());
        return 1;
        }
        combat_message_vision(HIC "\n$N"+HIC"忽然由頂至踵分為兩片，向兩邊倒了下去！！\n" NOR , target);
//        target->set_temp("last_damage_from",me);
        target->die();
        me->delete_temp("kill_other");
       // me->start_busy(4);
      //  me->add("bellicosity",100);
        return 1;


                      //  }


						/*target->start_call_out( (: call_other, __FILE__, "kill_him2", me, target :), 3+random(5));
							    me->remove_killer(target);
                        target->remove_killer(me);
             return 1;*/
                }
                       if (random(dance+extra)>extra) {
                        		combat_message_vision(HIC"
$N有如敦煌壁畫上的天女一般，提足如神山飛渡，側臉如桃花相映，旋身如飛
燕投林，這一舞，宛似舞了一座江南一處長安，一時間千變萬幻，蜃影重重；一
時間淋漓暢盡，似飄似颺。\n"NOR,target);
	message_vision(HIR "\n$N一刀竟然劈到空處！！\n" NOR , me);
	   me->delete_temp("kill_other");
   if (me->query_busy()<2) me->start_busy(2);
        return 1;
                        }
if( COMBAT_D->do_magic(me,target,"wuli") )
{
combat_message_vision(WHT"\n\n雖然$n"+NOR WHT"根本沒有看清楚，但是可以感覺到。。。"+BLINK HIW"$N"+BLINK HIW"已然出刀！\n"NOR, me, target);
combat_message_vision(HIC "\n$N"+HIC"忽然感覺到一陣刀氣撲面而來，$N閃躲不及，被打了個正著！！\n" NOR , target);
rkee = target->query("resistance/kee");
extra = me->query_skill("moon-blade",1);
//target->add_temp("resistance/kee",-rkee);
damage = target->query("max_kee");
damage = damage * (10+random(5)) / 100 * extra / 150;
low_limit = extra*extra/30+random(extra*extra/20);
if(wizardp(me))
tell_object(me,"low_limit is "+low_limit+", damage is "+damage+"\n");
if(damage<low_limit)
damage = low_limit;

if (damage>100000) damage=100000+(damage-100000)/2;
if (damage>300000) damage=300000+random(damage-300000)/2;

target->receive_damage("kee",damage,me);
me->set_temp("timer/yuanyue",time());
COMBAT_D->report_status(target);
	  if (userp(me) && me->query("env/combat_test"))
                        tell_object(me,  HIG"( 你對" +
                                        target->query("name") +  HIG"造成"NOR WHT +
                                        damage + HIG"點傷害。)\n" NOR);
                if (userp(target) && target->query("env/combat_test"))
                        tell_object(target,  HIG"( 你受到" +
                                        me->query("name") + HIR + damage + HIG"點傷害。)\n" NOR);
//target->add_temp("resistance/kee",rkee);
if ( me->query_busy()<3 ) me->start_busy(3);



}

else
{
combat_message_vision(YEL"但$n"+NOR YEL"就地一滾，總算躲過了$N"+NOR YEL"這無形的一招！\n\n"NOR, me, target);
if (me->query_busy()<2) me->start_busy(2);
}
return 1;
}


void kill_him2(object me, object target)
{
        string msg;
        if (!target)
{
me->delete_temp("kill_other");
return;
}
 if (!me) return;
        if (target->query_skill("bloodghost",1)>random(me->query_skill("moon-blade",1))&&target->query("timer/bloodghost")+3600<time()) {
        	message_vision(HIR "\n$N見情勢不妙，霎時間急運血魔神功中的『化血為身』！！\n" NOR , target);
        	 message_vision(HIC "\n$N"+HIC"忽然由頂至踵分為兩片，向兩邊倒了下去！！\n" NOR , target);
        	 	message_vision(HIR "\n$N化作一灘血水，原來被打中的只是$N以血換化的假身！！\n" NOR , target);
        	 	   me->delete_temp("kill_other");
        me->add("bellicosity",100);
        me->kill_ob(target);
        target->kill_ob(me);
        target->set("timer/bloodghost",time());
        return;
        }
        message_vision(HIC "\n$N"+HIC"忽然由頂至踵分為兩片，向兩邊倒了下去了！！\n" NOR , target);
        target->set_temp("last_damage_from",me);
        target->die();
        me->delete_temp("kill_other");
        me->add("bellicosity",100);
        return;
}
