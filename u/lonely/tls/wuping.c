
inherit ROOM;

void create()
{
	set("short", "物品房");
	set("long", @LONG
這裡是天龍寺內的物品房，房間堆的滿滿的，你看了看，到處是
一排排的大木架，架上放著許多物品，卻不粘灰塵，看樣子隨時都有
人來打掃。南面過去是慈悲院。
LONG);
	set("exits", ([ 
           "south" : __DIR__"cby",
        ]));
	set("coor/x",-340);
  set("coor/y",-270);
   set("coor/z",30);
   setup();
}
void init()
{
      // add_action("do_clean", ({"clean","打掃"}))
}

int do_clean(string arg)
{
     object me=this_player();

     if(arg != "木 架" ){
          message_vision("$N你認真的把物品房打掃了一遍。\n", me);
          return 1;
          }
     if(random(100) < 5){               
           message_vision("$N正認真的打掃著物品房中的木架上堆放的各式物品，
一本破舊的書突然從木架縫中掉了下來。\n", me);
           new("/clone/medicine/m-book4")->move(me);
           }
     else message_vision("$N你認真的把物品房打掃了一遍。\n", me);
     return 1;
}
