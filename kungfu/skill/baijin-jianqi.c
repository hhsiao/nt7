// redl 2015
#include <ansi.h>;

inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }
inherit SKILL;
//青木白金離火玄水厚土
//《禮記·王制》“天子將出，類乎上帝” 孔穎達 疏引 庾蔚之 曰：“五行各有德，故謂五德之帝。木神仁，金神義，火神禮，水神知，土神信。” 
//宋 丘光庭 《兼明書·五行神》：“木神曰 勾芒 ，火神曰 祝融 ，土神曰 后土 ，金神曰 蓐收 ，水神曰 玄冥 。土神獨稱後者，後，君也，位居中，統領四行，故稱君也。
string name() { return HIW "白金" HIC "劍氣" NOR; }


int valid_research(object me)
{
        if( query("max_neili", me)<100000 )
                return notify_fail("你的內力不夠。\n");
        if( query("level", me)<50 )
                return notify_fail("你的人物等級不夠。\n");
        if( me->query_skill("force-cognize",1 )<1500 )
                return notify_fail("你的內功修養等級不夠。\n");
        if( me->query_skill("martial-cognize",1 )<2500 )
                return notify_fail("你的武學修養等級不夠。\n");
        if( me->query_skill("sword",1 )<3500 )
                return notify_fail("你的基本劍法等級不夠。\n");
        if (me->query_skill("martial-cognize", 1) < me->query_skill("baijin-jianqi", 1))
                return notify_fail("你的武學修養太差。\n");                
        if (me->query_skill("sword", 1) / 3 < me->query_skill("baijin-jianqi", 1))
                return notify_fail("你的基本劍法太差。\n");                
        if( query("gcjinchuan_yuancizhenqi/1", me)<1 )        
                        return notify_fail(HIC "你修行"+ name() + HIC "需要的金行元磁力不夠。\n" NOR);
        tell_object(me, NOR "你從身體裡逼起一股金行元磁力，緩緩運行周身經脈。\n" NOR);          
        addn("gcjinchuan_yuancizhenqi/1", -1, me);
        return 1;
}

int valid_enable(string usage) { return usage == "taoism"; }

int difficult_level() 
{ 
        return 3000; 
} 

// string perform_action_file(string action)
// {
//         return __DIR__"qingmu-zhenqi/"+ action;
// }

int help(object me)
{
        write(HIC"\n"+name()+HIC"："NOR"\n");
        write(@HELP
    據說是上古蓐收氏族的修行功法，借元磁力修煉的道術，在施展絕學的同時困擾敵人。
        學習要求：
                等級50
                內力100000
                內功修養1500
                武學修養2500
                基本劍法3500
HELP
        );
        return 1;
}

