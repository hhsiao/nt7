// jingxin.c 靜

#include <ansi.h>

int exert(object me)
{
	int skill;
	skill = me->query_skill("literate", 1)/2;

	if(me->is_fighting())
	      return notify_fail("你正在戰鬥中，如何可以靜下心來？\n");

	if((int)me->query_skill("qiantian-yiyang",1) < 100 )
	      return notify_fail("你的乾天一陽功不夠嫻熟，內力的衝撞使你靜不下心來！\n");

	if(me->query("class") != "bonze" )
	      return notify_fail("你沒有出家，內力的衝撞使你靜不下心來！\n");

	if((int)me->query_skill("buddhism",1) < 50 )
	      return notify_fail("你的佛學修為不夠，無法靜下心來潛修！\n");

	if (me->query("neili") < 300  ) 
		return notify_fail("你的內力不夠。\n");

	if (me->query_temp("dali_jing"))
		return notify_fail("你正在靜心潛修。\n");
       
	me->add("neili", -250);

	message_vision(GRN "\n$N閉目盤膝坐下，只覺心中清靜平和，漸漸進入忘我之境。\n" NOR, me);

	me->set_temp("dali_jing", me->query("int"));  
	me->add_temp("apply/intelligence", me->query("int"));

	call_out("remove_effect", 1, me, skill);
	return 1;
}

void remove_effect(object me, int d)
{
	int i;

	if (!me) return;
	if (me->query_skill_mapped("force") == "qiantian-yiyang"
	 && --d > 0) {
		call_out("remove_effect", 1, me, d);
		return;
	}
	i = me->query_temp("dali_jing");
	me->add_temp("apply/intelligence", -i);
	me->delete_temp("dali_jing");
	tell_object(me, HIY "你心中雜念又生，無法繼續潛修了。\n" NOR);
}

string exert_name(){ return GRN"心經"NOR; }

int help(object me)
{
        write(GRN"\n乾天一陽功之「心經」："NOR"\n\n");
        write(@HELP
        要求：  當前內力 550 以上；
                乾天一陽功等級 100 以上；
                禪宗心法等級 50 以上；
                必須出家。

HELP
        );
        return 1;
}
