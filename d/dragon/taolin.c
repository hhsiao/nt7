inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "桃林");
        set("long",
"[1;32m這是片茂密的桃林(peachtree)，林中芳草鮮美，落英繽紛，\n"
"一層淡淡的薄霧，混合著青青的草香，瀰漫在空氣之中。偶爾的一兩聲鳥\n"
"鳴，愈發地顯出幽靜來。這裡的小路已被落花鋪滿，早已辨不出痕跡來。\n"
"[2;37;0m\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"lake1",
]));

        set("item_desc", ([
            "桃樹": "粉雲彩霞般的桃花，熱熱鬧鬧地開滿了枝頭。\n",
            "peach tree": "粉雲彩霞般的桃花，熱熱鬧鬧地開滿了枝頭，讓人忍不住想摘(pick)一枝桃枝(taozhi)下來。\n",
        ]) );

        set("no_magic", 1);
        setup();
}

void init() 
{
   add_action("do_pick", "pick");
}

int do_pick(string arg)
{
   object me, where, zhi;

   me = this_player(); 
        where=environment(me); 
   if(!arg || arg != "taozhi" && arg != "桃枝") return 0;       
   if( query_temp("marks/taozhi", where)){
      tell_object(me, "\n再摘桃樹就禿了! \n");  
      return 1;
   }    
   zhi = new("/quest/tulong/obj/taozhi");
   zhi->move(me);
   set_temp("marks/taozhi", 1, where);
   message_vision("\n$N伸手摘了一枝桃花下來。\n", me);
        
   return 1;    
}
