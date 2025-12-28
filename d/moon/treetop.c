// ken 1999.12.9
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{    set("short", "枯樹頂");
        set("long", @LONG
這棵樹還算高大，可惜已枯死多年。這裡四下漆黑，只是遠方隱隱
似有燈光閃耀。你看著腳下的白霧，舉棋不定，躊躇不前....
LONG
        );
       	set("coor/x",-10);
	set("coor/y",1010);
	set("coor/z",10);
        set("no_magic",1);
        set("item_desc", ([
         "白霧": "看來想越過這團白霧，只能靠施展輕功了。(jump)\n",
	 "燈光" : "想靠近這隱約的燈光，只好憑運氣闖一闖了。(jump)\n",
		        ]) );
	setup();
}

void init()
{
        add_action("do_jump", "jump");
}
int jumpbusy(object me)
{  object room;
  message_vision("\n只聽一陣衣衫撕裂和樹枝折斷的聲音，然後$N重重地摔到了地上...\n\n",me);  
         me->unconcious();
         room = find_object("/d/yuanyue/zz7");
         if(!objectp(room)) room=load_object("/u/moon/zz7");   
         me->move(room);    
         return 1;
}

int jumpbusya(object me)
{  object room;
 message_vision("\n$N突然發覺內力不濟，心中暗叫不妙,身形已向下急墜!\n\n",me);
         room = find_object("/d/yuanyue/zz2");
         if(!objectp(room)) room=load_object("/u/moon/zz2");
         me->move(room);
         me->start_busy(5);
         return 1;
}

int jumpbusyb(object me)
{  object room;
   write("\n你順利地飛越了腳下的濃濃白霧,輕輕的落在一大片草地上...\n\n" );
         room = find_object("/n/moon/caodi");
         if(!objectp(room)) room=load_object("/u/moon/caodi");
         me->move(room);
//       me->set("force",random(200));
         return 1;
}

int do_jump(string arg)
{
	object me;
        int aa,bb;
   	me = this_player();
        aa = me->query_skill("move",1);
        bb = me->query("force");
        if( !arg || arg=="" ) 
        return notify_fail("你想向哪個地方跳？\n");
        if( arg=="out" || arg=="燈光") 
 {    
         if(aa < 30)
     {  message_vision("\n$N橫下心來，閉上眼睛，猛地向外跳了出去....\n",me); 
        me->start_busy(1);
        call_out("jumpbusy",1,me);
        me->stop_busy();
        return 1;
      }
         else 
message_vision("\n$N展開身形，御風而起，勇敢地向無邊的黑暗掠去......\n",me);
        
	if( bb < 200 )
      {  me->start_busy(1);
          call_out("jumpbusya",1,me);
          me->stop_busy(); 
	 return 1;						
      }
else    
      {  me->start_busy(1); 
         call_out("jumpbusyb",1,me); 
         me->stop_busy(); 
 	 return 1;						
      }
 }
	write("你想向哪個地方跳？\n");
}

