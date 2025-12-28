//COOL@SJ 200001009 add yyz liao yyz_hurt
#include <ansi.h>

string exert_name() {return HIY"純陽療傷"NOR;}

int exert(object me, object target)
{
	if( !objectp(target) )
		return notify_fail("你要用一陽指為誰療傷？\n");

	if (target->is_corpse() || !target->is_character())
		return notify_fail("那不是活物耶！\n");

	if (target->is_busy())
		return notify_fail("對方現在沒有空接受你的療傷。\n");

	if((int)me->query_skill("force") < 270 )
	      return notify_fail("你的乾天一陽功不夠嫻熟，無法替人療傷！\n");

	if((int)me->query_skill("yiyang-zhi",1) < 180 )
	      return notify_fail("你的一陽指神功不夠嫻熟，無法替人療傷！\n");

	if (me->query_skill_prepared("finger") != "yiyang-zhi"
	|| me->query_skill_mapped("finger") != "yiyang-zhi")
		return notify_fail("你現在無法使用一陽指替人療傷！\n");

	if( me->is_fighting() && target != me)
		return notify_fail("戰鬥中無法替別人療傷！\n");

        if( target->is_fighting()&&target != me)
                return notify_fail("對方正在戰鬥，無法替他療傷！\n");

	if( (int)me->query("max_neili") < 2000 )
		return notify_fail("你的內力修為不夠。\n");

	if( (int)me->query("neili") < 400 )
		return notify_fail("你的真氣不夠。\n");

	if((int)me->query_skill("medicine", 1) < 120 )
	       return notify_fail("看樣子你的醫理知識所知甚少，不知如何下手? \n");

	if (!target->query_condition("yyz_hurt")
	&& target->query("eff_qi") >= target->query("max_qi"))
		return notify_fail( target->name() + "並沒有受傷！\n");

	if (me->is_fighting()) {
		message_vision(
			HIY"\n$N手臂顫動，猶如蜻蜓點水，一口氣連點過自己胸口的十二道大穴，純陽真氣不斷透入……\n\n"
			HIM"只這片刻之間，$N臉色便有了紅暈，傷勢好多了。\n" NOR, me);
		if (target->query_condition("yyz_hurt")) target->clear_condition("yyz_hurt");
		if ((int)target->query("eff_qi") < (int)target->query("max_qi"))
		{
			me->add("neili",-me->query_skill("force")/3);
			me->receive_curing("qi", 10 + me->query_skill("force") );
			me->receive_heal("qi", 10 + me->query_skill("force"));
		}
		me->start_exert(5, "療傷");
	} else {
		target->start_busy(2);
	  	if (target != me){
			me->start_busy(2);
	    		message_vision(HIY"\n$N伸出右手食指，微一凝氣，聽得嗤嗤聲響, 食指沿任、督二脈各穴依此點過，最後按在$n胸口的膻中大穴上，純陽內力源源透入。。。\n\n"
			   	HIM"\n$N頭頂冒起絲絲白氣，$n感覺一股溫正平和的內力在體內循環流動，過了一盞茶時分，$N才放開手指。只這片刻之間，$n雙頰\n"
			   	HIM"便有了紅暈，臉色看起來也好多了。\n" NOR,me,target);
		}
		else
	   		message_vision(HIY"\n$N盤腿坐下，微一凝氣，食指依任、督二脈各穴依此點過，食指一收，虛掌按在胸口膻中大穴，純陽真氣源源透入。。。\n\n"
				HIM"$N頭頂冒起絲絲白氣，過了一盞茶時分，才放開手指,$N的臉色看起來也好多了。\n" NOR,me);
	   	if( (target != me)
	    	&& userp(target)
	    	&& target->query("eff_qi") < target->query("max_qi")/5) {
	     		if (!random(4)) me->add("max_neili",-1);
	     		me->add("yyz_cure",1);
		}
		if (target->query_condition("yyz_hurt")) target->clear_condition("yyz_hurt");
		if (target->query("eff_qi") < target->query("max_qi"))
		{
		   	me->add("neili", -me->query_skill("force")/4);
	   		target->receive_curing("qi", 10 + me->query_skill("force"));
	   		target->receive_heal("qi", 10 + me->query_skill("force"));
	   		me->start_busy(3);
	   		target->start_busy(3);
	 	}
	}
	return 1;
}
