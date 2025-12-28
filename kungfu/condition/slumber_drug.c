// slumber_drug.c

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int limit;

	limit=query("neili", me)/50;

	tell_object(me, "你覺得腦中昏昏沉沉，心中空蕩蕩的，直想躺下來睡一覺。\n");
	message("vision", me->name() + "搖頭晃腦地站都站不穩，好像喝醉了一樣。\n",
		environment(me), me);
	if( duration > limit ) {
		if ( living(me) ) me->unconcious();
		return 0;
	} else 
        if( query("neili", me)>500){
	        tell_object(me, "你發覺不妙，猛吸一口氣，登時清醒了不少。\n");
                addn("neili", -100, me);
                return 0;
	}

        if ( duration > 1 )
        {
                me->apply_condition("slumber_drug", duration - 1);
                return 1;
        }

	return 0;
}