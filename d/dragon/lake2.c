inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "三清湖");
        set("long",
"[1;32m湖水清澈透明，不時可以看到幾尾魚跳上水面。湖水盡頭是\n"
"一個大瀑布。在這裡可以聽到瀑布從山上直衝而下，發出的轟轟雷聲。湖\n"
"邊一塊巨石，上寫＂三清湖＂。這裡風非常大，吹得人得衣衫獵獵做響。\n"
);
   set("exits", ([ 
      "northeast" : __DIR__"lake1",
   ]));

        set("no_magic", 1);
        setup();
}

void kite_notify(object obj, int i)
{
   object  me, room;
   int j;
        
   me = this_player();
   message_vision("突然一陣微風拂過"+obj->name()+"緩緩的升了起來，越來越高。\n\n" , me);
   switch( random(2) ) {
   case 0:
      tell_object(me, me->name()+"手中的"+obj->name()+"越飛越高。 \n");
      message_vision("只聽一陣清悅的哨音從高空傳過！ \n", me);
      call_out("boat_come", 2, me);
   break;
   case 1:
      message_vision("一陣勁風吹過，$N手中的線斷了，"+obj->name() 
+"越來越高，慢慢的不見了。 \n",me);
      destruct(obj);
      break;
   }
   return; 
}

void boat_come(object me)
{
   object  boat, *inv, ob;
   int i;
        

   if (query("exits/down")) return ;
   if (!objectp(boat=find_object(__DIR__"boat")))
      boat=load_object("/u/night/room/boat");
   inv=all_inventory(boat);
   for(i=0; i<sizeof(inv); i++) {
      ob = inv[i];
      if(living(ob)){
         message("vision","半晌，湖上還是沒有絲毫動靜。\n",this_object()); 
         return;
      }
   }
   message("vision","過了半晌，一葉小舟緩緩地從霧中盪出，靠到了湖邊。\n",this_object()); 
    set("exits/up", __DIR__"lake2", boat);
  set("exits/down",__DIR__"boat");
   call_out("boat_leave",10,boat);
   return ;
}

void boat_leave(object boat)
{
        if (query("exits/down")) delete("exits/down");
        if( query("exits/up", boat))delete("exits/up", boat);
        message("vision","一陣微風拂過，小船蕩離了岸邊。\n",this_object()); 
        message("vision","一陣微風拂過，小船蕩離了岸邊。\n",boat); 
        return;
}

int valid_leave(object me, string dir)
{
   object *inv, boat, ob;
   int i;

   if (userp(me) && dir == "down") {
      boat=find_object(__DIR__"boat");
      if (!objectp(boat))
         boat=load_object(__DIR__"boat");
         inv=all_inventory(boat);
            for(i=0; i<sizeof(inv); i++) {
               ob = inv[i];
               if(living(ob)){
                  tell_object(me, "船太小了，只能乘坐一個人。\n");      
                  return notify_fail("");
               }
           }
   }
   return 1;
}
