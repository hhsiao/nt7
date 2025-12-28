// Silencer@fengyun June.2005
// L50： 『中流』Super defense stance

#include <ansi.h>
#include <combat.h>
#define S_TIME 480 // 最多使用8分鐘，每次60秒
#define L_TIME 3600 // 一小時復原

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg, type;
	int duration, extra, add, skill, num, amount;
	mapping buff, data;
	object weapon;

	extra = me->query_skill("fall-steps",1);
	skill = me->query_skill("six-sense",1);
	if( extra < 150 || skill < 150 || me->query_skill("dormancy",1) < 150 ) {
		return notify_fail("『中流』需要150級的秋風步、六靈暗識、息若納氣！\n");
	}
	if( !target ) {
		target = me;
	}
	if( target != me ) {
		return notify_fail("『中流』只能用在自己身上。\n");
	}
	if( ANNIE_D->check_buff(me,"afm-absshield") ) {
		return notify_fail("你已經在使用中流中了。\n");
	}
	// 初始化
	if( me->query("timer/tx-zhongliu") < 1 ) {
		me->set("timer/tx-zhongliu",time());
		me->set("timer/pfm/tx-zhongliu",S_TIME);
	}
	if( me->query("timer/tx-zhongliu") + L_TIME < time() ){
		me->set("timer/tx-zhongliu",time());
		me->set("timer/pfm/tx-zhongliu",S_TIME);
	}
	if( me->query("timer/pfm/tx-zhongliu") < 50 ) {
		duration = L_TIME + me->query("timer/tx-zhongliu") - time();
		return notify_fail("你還要等待"+ (duration/60)+"分鐘才能再次使用中流。\n");
	}
	duration = 60;
	me->add("timer/pfm/tx-zhongliu",-60);
	if( weapon = me->query_temp("weapon") ) {
		if( weapon->query("skill_type") == "sword" ) {
			msg = "$N劍法一變，從極快而變為極慢，劍尖上墜了千斤重物似的，慢騰騰的東刺一劍，西\n刺一劍，身畔周圍八尺之內，便似布起了一道鐵壁銅牆一般。\n";
		} else if( weapon->query("skill_type") == "blade" ) {
			msg = "$N刀法一變，從極快而變為極慢，刀尖上墜了千斤重物似的，慢騰騰的東劈一刀，西\n劈一刀，身畔周圍八尺之內，便似布起了一道鐵壁銅牆一般。\n";
		}
	}
	if( !msg ) {
		msg = "$N招式瞬息萬變，有如大海潮生，一渡末平，一波又起，周圍八尺之內，便似布起了一道鐵壁銅牆一般。\n";
	}
	add = me->query("timer/pfm/tx-zhongliu")/60;
	amount = 200 - ABILITY_D->check_ability(me,"3_zhongliu_add",3)*20;
	data =
	        ([
                   "reduce_damage" : 50,
	                "attack" : -amount,
	        ]);

	buff =
		([
			"caster": me,
			"who": me,
			"type": "afm-absshield",
			"type2": "tx-turtle-stance",
			"att": "bless",
			"name": "秋風步·中流",
			/*
			"buff1": "resistance/kee",
			"buff1_c": 50,
			"buff2": "apply/attack",
			"buff2_c": -amount,
			*/
			"buff_data" : data,
			"buff_type" : "afm-absshield",
			"shield_type": "neili",
			"shield_amount": 50,
			"shield_msg": "",
			"time": 60,
			"buff_msg": BRED + HIY +msg+NOR,
		]);
	ANNIE_D->buffup(buff);

	write(WHT"（在接下來的"+ ((me->query("timer/tx-zhongliu") + L_TIME - time())/60) + "分鐘裡你還能使用"+ add + "次中流）\n"NOR);
	return 1;
}
