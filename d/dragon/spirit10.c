inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "小屋裡");
        set("long",
"[1;32m這是一間樸素的小木屋，屋中的擺設都是些簡單必要的傢俱\n"
"。窗下是一張小几，上面放著一些食物。一個精靈族的女子正在屋中忙碌\n"
"著什麼。\n"
); 
        set("objects", ([ 
            "/quest/tulong/npc/spiritgirl" : 1,
            "/quest/tulong/npc/kid" : 1,
          ]));        
        set("exits", ([ /* sizeof() == 4 */
           "east" : __DIR__"village",
   ]));

        setup();
//        replace_program(ROOM);

}

void init()
{
  add_action ("do_search","search"); 
}

int do_search (string arg)
{
  object who = this_player ();
  object where = this_object ();
  object hook;
 
        if (  present("hook", who) ) {
                return notify_fail("你不是已經找到了嗎？\n");
          }
  if (random(10))
  {
    message_vision ("$N四處搜索了一番，什麼也沒有找到。\n",who);  
  }
  else
  {
    hook = new ("/quest/tulong/obj/hook");
    message_vision ("$N把小屋的大小角落都找了個遍，發現了一個小鉤子！\n",who,hook);
    hook->move(who);  
  }
  return 1;
}
