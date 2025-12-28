#include <ansi.h>
inherit ITEM;

mapping cb_ob = ([ 
        "rune21" : "puti zi",
        "rune22" : "jiuzhuan jindan",
        "rune23" : "magic water",
        "rune24" : "xuanhuang dan",
        "rune25" : "feicui lan",
        "rune26" : "god blood",
        "rune27" : "flawless topaz",
        "rune28" : "flawless ruby",
        "rune29" : "flawless sapphire",
        "rune30" : "flawless emerald",
        "rune31" : "flawless diamond",
        "rune32" : "magic topaz",
        "rune33" : "magic ruby",
]);

void do_reset()
{
	delete_temp("do_busy");
}

void create()
{
        set_name(HIW "符文合成器" NOR, ({ "cb rune" }) );
        set_weight(3000);

        set("long", HIW @LONG
這是一個可以用來快速合成升級符文的神器，你需要將準備合成的材料放在身上就可以了。

合成符文    cb <符文> 例如：cb rune09，表示將要合成為符文rune09

LONG NOR );
        set("value", 200000);
        set("unit", "臺");
        set("no_get", 1);

        setup();
}

void init()
{
        if( !playerp(this_player()) ) return;
        
        add_action("do_cb", "cb");
}

int do_cb(string arg)
{
        object ob, me;
        object *obs, *obs1, *obs2;
        string a, name, str;
        int i, n, k, t1, t2;
        
        me = this_player();
                
        if( me->is_busy() ) return notify_fail("你正忙著呢！\n"); 
        if( query_temp("do_busy") ) return notify_fail("符文合成器氣喘噓地嘆道：慢慢來 ....\n");  

        if( !arg || strsrch(arg, "rune") < 0 ) 
                return notify_fail("你想要合成什麼？格式:cb rune09\n");     
      
        sscanf(arg, "rune%s", a); 
        n = to_int(a);
        if( n < 2 || n > 33 )
                return notify_fail("你想要合成什麼？格式:cb rune09\n");
 	
 	set_temp("do_busy", 1);
 	remove_call_out("do_reset");
 	call_out("do_reset", 2);
 	
        if( n > 10 ) {
                str = "rune"+(n-1);
                arg = "rune"+n;
        }
        else {
                str = "rune0"+(n-1);
                if( n == 10 ) arg = "rune10"; 
                else arg = "rune0"+n;
        }
               
        if( n < 21 ) {          
                obs1 = filter_array(all_inventory(me),(:query("id", $1) == $(str) && !$1->is_item_make():)); 
                k = sizeof(obs1)/3;
                if( k < 1 ) {
                        write(HIG "你沒有準備足夠的符文合成所需材料。\n");
                        me->start_busy(1);
                        return -1;
                }
                if( k > 1000 ) k = 1000;
                for( i=0;i<k*3;i++ ) 
                {
                        if( objectp(obs1[i]) )
                                destruct(obs1[i]);

                        if( i < k ) {
                                ob = new("/clone/tessera/"+arg);
                                ob->move(me);
                        }
                }
                write(HIW "只見符文合成器發出一道白光從你身上掃過，你發現身上的符文似乎發生了某些變化。\n");
                return 1;
        }
                
        name = cb_ob[arg];
                
        obs = all_inventory(me);
        obs1 = filter_array(obs,(:query("id", $1) == $(str) && !$1->is_item_make() :)); 
        obs2 = filter_array(obs,(:query("id", $1) == $(name) && !$1->is_item_make() :));
        
        t1 = sizeof(obs1)/2;
        t2 = sizeof(obs2);
        
        k = min(t1, t2);
        if( k < 1 ) {
                me->start_busy(1);
                write(HIG "你沒有準備足夠的符文合成所需材料。\n");
                return -1;
        }
        
        if( k > 1000 ) k = 1000;
        	   
        for( i=0;i<k*2;i++ )
        {
                if( objectp(obs1[i]) )
                        destruct(obs1[i]);


                if( i<k && objectp(obs2[i]) ) {
                        destruct(obs2[i]);
                        ob = new("/clone/tessera/"+arg);
                        ob->move(me);
                }
        }
        write(HIW "只見符文合成器發出一道白光從你身上掃過，你發現身上的符文似乎發生了某些變化。\n");          
        me->start_busy(1);
        return 1;        
}
