// surge-force.c 怒海狂濤

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_force(string force) { return 1; }

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("surge-force", 1);
        
        if( query("can_perform/surge-force/new", me) )
        	return lvl * lvl / 100 * 15 * 38 / 200;
        	
        return lvl * lvl / 100  * 15 * 19 / 200;
}

int valid_learn(object me)
{
        if( query("gender", me) != "男性" && !query("yuanshen_level", me) )
		return notify_fail("你不具有男性的陽剛之氣，無法修習怒海狂濤。\n");

	if ((int)me->query_skill("force", 1) < 150)
		return notify_fail("你的基本內功火候還不夠，還不能修煉怒海狂濤。\n");

        if (me->query_str() < 45)
                return notify_fail("你的膂力不足，難以修習怒海狂濤。\n");

	if( query("can_perform/surge-force/new", me) )
	{
		if( query("int", me)<40 || query("con", me)<30 )
			return notify_fail("你先天屬性不足，難以學成怒海狂濤。\n");
		
		if (me->query_skill("force", 1) < 1000)
			return notify_fail("你基本內功修為不足，無法修煉怒海狂濤。\n");
			
		if( query("max_neili", me)<35000 )
			return notify_fail("你內力修為不足，無法修煉怒海狂濤。\n");	
		
		if (me->query_skill("taoism", 1) < 1)
			return notify_fail("你道學心法修為不足，無法修煉怒海狂濤。\n");	
			
		if (me->query_skill("xuantie-jian", 1) < 1)
			return notify_fail("你玄鐵劍法修為不足，無法修煉怒海狂濤。\n");					
			
		if (me->query_skill("martial-cognize", 1) < 1200)
			return notify_fail("你武學修養不足，無法修煉怒海狂濤。\n");		
			
		if (me->query_skill("jiuyin-shengong", 1) < 1 && 
		    me->query_skill("jiuyin-hamagong", 1))
		    	return notify_fail("你未曾練成過九陰真經，無法修煉怒海狂濤。\n");	
			
		if (me->query_skill("surge-force", 1) > me->query_skill("force", 1))
			return notify_fail("你基本內功修為不足，無法繼續修煉怒海狂濤。\n");			
	}
		
	return ::valid_learn(me);
}

int practice_skill(object me)
{
	return notify_fail("怒海狂濤只能用學(learn)的來增加熟練度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"surge-force/" + func;
}

int difficult_level()
{
        //return 4000;
        return 100;
}
