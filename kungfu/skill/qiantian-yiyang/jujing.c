// jujing.c 聚精成氣
// by augx@sj  6/11/2002

#include <ansi.h>

int exert(object me)
{
	int i;

	if ( me->query("tls"))
		return notify_fail("你已經出家了，怎麼能用此種俗家武功！\n");

	if ( me->query("family/master_name") != "一燈大師" )
		return notify_fail("你非一燈弟子，經脈恐怕受不了怎麼大的內力衝擊。\n");

	if (me->query_skill("qiantian-yiyang",1) < 300 )
		return notify_fail("你的乾天一陽功不夠嫻熟，無法「聚精成氣」。\n");

	if( me->query_skill_mapped("force") != "qiantian-yiyang" )
		return notify_fail("你所使用的內功不對。\n");

	if ( me->query_skill("yiyang-zhi", 1) < 300 )
		return notify_fail("你的一陽指等級不夠，無法「聚精成氣」。\n");

	if ( me->query_skill_mapped("finger") != "yiyang-zhi"
	|| me->query_skill_prepared("finger") != "yiyang-zhi") 
		return notify_fail("你必須結合一陽指使用「聚精成氣」。\n");

	if (me->query("max_neili") < 6000  )
		return notify_fail("你的內勁修為不夠。\n");

	if (me->query("neili") < 3000  )
		return notify_fail("你的內力不夠。\n");

	if (me->query("max_jing") < 2000  )
		return notify_fail("你的精血不足。\n");

	if (me->query("jing") < 2000  )
		return notify_fail("你的精血不足。\n");

	if (me->query_temp("dali/jujing"))
		return notify_fail("你已經使用「聚精成氣」了。\n");

	message_vision(HIY"\n$N凝神聚氣，臉色數變，只感覺頭腦一下子空白，膚色紅潤了許多。\n"NOR, me);

	i = me->query_skill("qiantian-yiyang",1);
	i = i * i / 60;
	i = MIN(i,me->query("jing")-100);
	i = MIN(i,me->query("neili"));

	me->add("neili", -i);
	me->add("max_jing",-i);
	me->add("eff_jing",-i);
	me->add("jing",-i);
	me->add("max_qi",i);
	me->add("eff_qi",i);
	me->add("qi",i);
	if (me->query_skill("qiantian-yiyang",1)>449)
	{     
       me->set_temp("apply/attack",me->query_skill("qiantian-yiyang",1)/5);
	 if (me->query("tls/yideng/ronghe")=="pass")
	  {message_vision(HIC"\n$N瞬間領悟到一燈大師所提到的「先天功」的奧義，手上的力道明顯增強了不少。\n"NOR, me);
	   me->set_temp("apply/damage",me->query_skill("qiantian-yiyang",1)/5);}
	 else
	   me->set_temp("apply/damage",me->query_skill("qiantian-yiyang",1)/10);
	
	}
   
	me->set_temp("dali/jujing", i);
	me->set("dali/jujing", i);
	me->set_temp("dali/jujing1", 0);
	if (me->query_skill("qiantian-yiyang",1)<449)
	{
	 if( me->is_fighting() ) me->start_busy(random(2));
	 me->start_exert(3, "聚精成氣");
	}
		

	call_out("remove_effect", 6, me, 3+me->query_skill("qiantian-yiyang", 1)/50);
	return 1;
}

void remove_effect(object me, int tick)
{
	int i;

	if(!me) return;
	if( me->query_skill_mapped("force")!="qiantian-yiyang" || !tick ) {
		tell_object(me, HIY"\n時間一長，你感覺支持不住，精神開始分散了。\n" NOR);
		i = me->query_temp("dali/jujing");
		me->delete_temp("dali/jujing");
		me->delete("dali/jujing");
		me->delete_temp("dali/jujing1");
        if (me->query_skill("qiantian-yiyang",1)>449)
	    {
		   me->set_temp("apply/attack",-me->query_skill("qiantian-yiyang",1)/5);
	     if (me->query("tls/yideng/ronghe")=="pass")
		   me->set_temp("apply/damage",-me->query_skill("qiantian-yiyang",1)/5);
	     else
	       me->set_temp("apply/damage",-me->query_skill("qiantian-yiyang",1)/10);
		 }
		me->add("max_jing",i);
		me->add("eff_jing",i);
		if( me->query("jing") > me->query("eff_jing") )
			me->set("jing",me->query("eff_jing"));

		me->add("max_qi",-i);
		if( me->query("eff_qi") > me->query("max_qi") )
			me->set("eff_qi",me->query("max_qi"));
		if( me->query("qi") > me->query("eff_qi") )
			me->set("qi",me->query("eff_qi"));
		return;
	}
	call_out("remove_effect", 6, me, tick-1);
}

string exert_name(){ return HIY"聚精成氣"NOR; }

int help(object me)
{
	write(HIY"\n乾天一陽功之「聚精成氣」："NOR"\n\n");
        write(@HELP
	聚精成氣是一燈大師從王重陽所授之先天功道家武學中參悟出來的，
	因此只傳授給俗家弟子。

	要求：	當前內力 550 以上；
		乾天一陽功等級 300 以上；
		一陽指等級 300 以上；
		激發指法為一陽指，備指法為一陽指；
		必須為俗家弟子,且拜師一燈。450級後有飛躍,增加命中和傷害。

HELP
        );
        return 1;
}
