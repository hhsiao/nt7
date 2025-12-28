//cool 98.7.17
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "大岩石");
	set("long", @LONG
你跳上了一塊大岩石，岩石上落腳的地方並不大，你看見岩石上坐著有人，
只是這人始終一動不動，身上又穿著青袍，與青巖同色。
LONG
	);
        set("outdoors", "大理");
        set("objects", ([
	    __DIR__"npc/dyq": 1,
	]));
	setup();
}

void init()
{
      add_action("do_jump","tiao");
      add_action("do_jump","jump");
}

int do_jump(string arg)
{
      object me;
      me = this_player();
      if (arg !="down") 
        return notify_fail("你要到那去？\n");
      if( arg=="down"){
        write("你縱身跳下了岩石。\n");
        message("vision",me->name() + "一縱身跳下了岩石。\n",environment(me), ({me}) );
        me->move(__DIR__"anbian");
        message("vision",me->name() + "走了過來。\n",environment(me), ({me}) );
        }
       return 1;
}