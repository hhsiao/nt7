inherit ROOM; 
#include <ansi.h> 
void init();
int do_take(string arg);
int do_back(object me);

void create()
{ 
      set("short", "演武臺");
      set("long",
"[1;32m這裡看上去象是一個比武場，十丈見方的場地上整整齊齊地\n"
"鋪著一圈彩色瑪瑙石，架著香菸裊繞的四個巨大金銀銅鐵鼎，場地中間還\n"
"鋪著軟松的皮絨織錦毯。在場邊有一個書架似的擺飾(shelf)，在它旁邊\n"
"還有一張絹帛(note)。\n"
);
   set("exits",([
           "south" : __DIR__"xiuxishi",
]));
  set("objects",([
             "/quest/tulong/npc/shadow" : 1,
  ]));
  set("item_desc", ([
     "shelf" : "這是一個藥架，裡面放著一些金創藥，似乎可以拿出來(take jinchuang)。\n", 
      "note" : "勇敢的人啊，如果你們的腳步到此為止，就回去凡間吧(back)。\n", 
  ]));
//  set("no_clean_up", 0);
  set("no_magic", 1);
        setup();
}

void init()
{
       // add_action("do_take", "take");
        add_action("do_back", "back");
      add_action("do_quit","hit");
      add_action("do_quit","kill");
      add_action("do_steal","steal");
}

int do_quit(string arg)
{
        write(query("name", this_player())+"，這裡只能fight！\n");
        return 1;
}

int do_steal(string arg)
{
        write(query("name", this_player())+"，不要為此不才之事！\n");
        return 1;
}
int do_take(string arg)
{      
        object me=this_player();
        object ob;
        if(!arg || arg!="jinchuang")
          return notify_fail("你要拿什麼？\n");
        if( !query("fighter", me) )
          return notify_fail("你還沒比武就想拿藥？\n"); 
       ob = new ("/clone/misc/jinchuang");   
       ob->move(me); 
  message_vision ("$N從臺上拿起$n。\n",me,ob); 
        return 1;  
}

int do_back(object me)
{
        me=this_player();
        message_vision(HIC"$N的身影消失在一陣光芒中。\n"NOR,me); 
        set("fighter", 0, me);
        set_temp("m_success/初級", 0, me);
        set_temp("m_success/幻影", 0, me);
        set_temp("m_success/孽龍", 0, me);
        me->move("/d/city/wumiao");
        return 1;
}

/*
int valid_leave(string dir)
{
              if((present("jinchuang yao", this_player())))
            return notify_fail("請不要帶走這裡的東西。\n"); 
        if((present("budai", this_player())))
            return notify_fail("請放下布袋，這裡的東西不能帶出去，謝謝。\n"); 
    return ::valid_leave();

 }

*/