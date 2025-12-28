#include <ansi.h>
inherit ITEM;

string *names = ({ "topaz", "ruby", "sapphire", "emerald", "diamond" });

void do_reset()
{
	delete_temp("do_busy");
}

void create()
{
        set_name(HIR "寶石合成器" NOR, ({ "hc gem" }) );
        set_weight(3000);

        set("long", HIR @LONG
這是一個可以用來快速合成升級寶石的神器，你需要將準備合成的材料放在身上就可以了。

合成寶石    hc <寶石> -<f|m> 例如：hc diamond -f，表示將要合成身上所有的diamond類寶石到flawless級別
                                   hc diamond -m，表示將要合成身上所有的diamond類寶石到magic級別

LONG NOR );
        set("value", 200000);
        set("unit", "臺");
        set("no_get", 1);

        setup();
}

void init()
{
        if( !playerp(this_player()) ) return;
        
        add_action("do_cb", "hc");
}

int do_cb(string arg)
{
        object ob, me;
        object *obs1, *obs2, *obs3;
        string a, name, str1, str2, str3, str4;
        string arg1, arg2, arg3;
        int i, k, flag=0;
        
        me = this_player();
                
        if( me->is_busy() ) return notify_fail("你正忙著呢！\n"); 
        if( query_temp("do_busy") ) return notify_fail("寶石合成器氣喘噓地嘆道：慢慢來 ....\n");  

        if( !arg || sscanf(arg, "%s -%s", name, a) != 2) 
        	return notify_fail("你想要合成什麼？格式:hc topaz -f\n"); 
        
        if( member_array(name, names) == -1 ) 
                return notify_fail("你想要合成什麼？格式:hc topaz -f\n");  
                	
        if( a != "f" && a != "m" )
        	return notify_fail("你想要合成到什麼級別 -f 或 -m ？\n");  
        
        set_temp("do_busy", 1);
 	remove_call_out("do_reset");
 	call_out("do_reset", 2);  	

        str1 = "chipped "+name;
        str2 = name;
        str3 = "flawless "+name;
        str4 = "magic "+name;
        
        arg1 = name;
        arg2 = "f"+name;
        arg3 = "m"+name;
        
        obs1 = filter_array(all_inventory(me),(:query("id", $1) == $(str1) && !$1->is_item_make() :)); 
        k = sizeof(obs1)/3;
        if( k > 1000 ) k = 1000;
   	for( i=0;i<k*3;i++ ) 
        {
            	if( objectp(obs1[i]) )
                  	destruct(obs1[i]);

              	if( i < k ) {
                     	ob = new("/clone/tessera/"+arg1);
                   	ob->move(me);
                }
                flag++;
	}
		
        obs2 = filter_array(all_inventory(me),(:query("id", $1) == $(str2) && !$1->is_item_make() :));
        k = sizeof(obs2)/3;
        if( k > 1000 ) k = 1000;
	for( i=0;i<k*3;i++ ) 
        {
            	if( objectp(obs2[i]) )
                  	destruct(obs2[i]);

              	if( i < k ) {
                     	ob = new("/clone/tessera/"+arg2);
                   	ob->move(me);
                }
                flag++;
	}
	
	if( a == "m" ) {	
        	obs3 = filter_array(all_inventory(me),(:query("id", $1) == $(str3) && !$1->is_item_make() :));
        	k = sizeof(obs3)/3;
        	if( k > 1000 ) k = 1000;
		for( i=0;i<k*3;i++ ) 
        	{
            		if( objectp(obs3[i]) )
                  		destruct(obs3[i]);

              		if( i < k ) {
                     		ob = new("/clone/tessera/"+arg3);
                   		ob->move(me);
                	}
                }
                flag++;
	}
        
        if( flag < 1 ) {
                write(HIG "你沒有準備足夠的寶石合成所需材料。\n");
                me->start_busy(1);
                return -1;
        }
                
        write(HIR "只見寶石合成器發出一道紅光從你身上掃過，你發現身上的寶石似乎發生了某些變化。\n");          
        me->start_busy(1);
        return 1;        
}

