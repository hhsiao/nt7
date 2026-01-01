// hua4.c

inherit ITEM;

#include <ansi.h>

void create()
{
	set_name(HIC "翡翠蘭" NOR, ({"feicui lan", "feicui", "lan"}));
   set("unit", "朵");
		set("long", "這是一朵千年難得一見的翡翠蘭，據說能解百毒。\n");
        	set("value", 1000000);
		set("only_do_effect", 1);
        setup();
}

int do_effect(object me)
{
        int time = 300;

        // vip的效果
        switch( me->query_viplevel() )
        {
        case 1:
                time = time - time / 10;
                break;
        case 2:
                time = time - time * 2 / 10;
                break;
        case 3:
                time = time - time * 3 / 10;
                break;
        case 4:
                time = time - time * 4 / 10;
                break;
        case 5:
                time = time - time * 5 / 10;
                break;
        case 6:
                time = time - time * 6 / 10;
                break;
        case 7:
                time = time - time * 7 / 10;
                break;
        }
        if( time < 10 ) time = 10;

        if( time()-query_temp("last_eat/feicui", me) < time )
        {
                write("你剛服用過藥，需藥性發揮完效用以後才能繼續服用。\n");
                return 1;
        }

        set_temp("last_eat/feicui", time(), me);
        me->clear_condition();
set("eff_jing",query("max_jing",  me), 	me);
set("jing",query("max_jing",  me), 	me);
set("eff_qi",query("max_qi",  me), 	me);
set("qi",query("max_qi",  me), 	me);
        message_vision("$N把" + name() + "扔進嘴裡，幾下就吞了下去。\n", me);
	tell_object(me, HIG "\n你只覺一股清香沁入心肺，頓時靈臺一片"
		        "空明，神意清爽！\n" NOR);
	destruct(this_object());
	return 1;
}
