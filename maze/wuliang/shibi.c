// shibi.c
// bbb 1997/06/11
// Modify By River 98/12
inherit ROOM;

void check_trigger();
void close_passage();
void reset();
string look_xiaoshi();
string look_dashi();

void create()
{
        set("short", "石壁下");
	set("long", @LONG
你在一塊大石壁(dashi)下，下面是一塊小石璧(xiaoshi)，上面爬滿了藤
蔓，縱橫交錯，地下枯黃的樹枝落葉積了好多層，看來很久這裡沒人來過了。
LONG
	);

	set("exits", ([
	      "out" : __DIR__"shuhou",
	]));
        set("outdoors", "大理");
	set("item_desc",([
           "dashi" : (: look_dashi :),
	   "xiaoshi" : (: look_xiaoshi :),
	]));

	setup();
}

void init()
{
	add_action("do_huang", "huang");
	add_action("do_tui", "tui");
        add_action("do_tear", "si");
	add_action("do_tear", "tear");
}

void check_trigger()
{

	if( (int)query("up_trigger")>=2
	&& (int)query("down_trigger")>=2
	&& !query("exits/enter") ) {
          message("vision", "岩石緩緩轉動，便如一扇大門似的，"
			"轉到一半，巖後露出一個三尺來高的洞穴。\n", this_object() );
	  set("exits/enter", __DIR__"dongkou");	
          delete("poem_teared");
	  delete("up_trigger");
	  delete("down_trigger");
	  remove_call_out("close_passage");
	  call_out("close_passage", 3);
	  }
}

void close_passage()
{
	if( !query("exits/enter") ) return;
	message("vision", "岩石忽然發出軋軋的聲音，緩緩地移回原處，"
		"將洞口蓋住了。\n", this_object() );
	delete("exits/enter");
}

int do_tui(string arg)
{
	string dir;
	if( !arg) return 0;
	if (arg == "dashi") {
	 if(!query("poem_teared"))
	   return notify_fail("上面爬滿了藤曼，你推不動。\n");
	 write("你試著推動這塊岩石，發現可以推動......\n");
	   return 1;
	   }
	if( sscanf(arg, "dashi %s", dir)==1 && (int)query("poem_teared") ) {
	 if( dir=="right" ) {
	  message_vision("$N將岩石推了推，岩石晃了晃，又移回原位。\n",this_player());
          addn("up_trigger", 1);
	  check_trigger();
	  return 1;
	  }
	  write("你要將大岩石推向那個方向？\n");
	  return 1;
	  }
      return notify_fail("你要推什麼？\n");
}

int do_huang(string arg)
{
	string dir;
	if( !arg) return 0;
	if (arg == "dashi") {
	  if(!query("poem_teared"))
	   return notify_fail("上面爬滿了藤曼，你晃不了。\n");
	   write("你試著晃動這塊岩石，發現可以推動......\n");
	   return 1;
	   }
	if( sscanf(arg, "dashi %s", dir)==1 && (int)query("poem_teared") ) {
	  if( dir=="left" ) {
	   message_vision("$N將岩石往左晃，岩石動了動，又移回原位。\n",this_player());
           addn("down_trigger", 1);
	   check_trigger();
	   return 1;
	   }
	   write("你要將大岩石晃向那個方向？\n");
	   return 1;
	   }
       return notify_fail("你要晃什麼？\n");
}

int do_tear(string arg)
{
	if( !arg || arg=="" )  return 0;
	if( arg =="cao" ){
          write("你要除草嗎？ !\n");
	  return 1;
	  }
	if( arg=="teng" ) {
	  write("你把大小岩石間的藤蔓盡數除去。\n");
	  addn("poem_teared", 1);
	  return 1;
	}
}

void reset()
{
	::reset();
	delete("poem_teared");
	delete("up_trigger");
	delete("down_trigger");
}

string look_xiaoshi()
{
	return
	 "很多的草藤之類纏在它的上面。\n";
}

string look_dashi()
{
	return
	"巖高齊胸，凌空置於一塊小岩石之上。\n";
}