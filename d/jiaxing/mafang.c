// mafang.c

inherit ROOM;

string look_daocao();

void create()
{
	set("short", "馬房");
	set("long", @LONG
這是楊鐵心家的後院的馬房，馬槽前面有個很大的水缸。
馬槽左邊堆滿了很多稻草，平時堆的很整齊，今天不知道怎
麼了，稻草(Daocao)堆的亂七八糟的。
LONG
	);

	set("exits", ([
		"south" : __DIR__"houyuan.c",
	]));
        set("objects",([
              // __DIR__"npc/wanyan": 1,
               	
        ]));
            
        set("item_desc",([
		"daocao" : (: look_daocao :),
	]));
        set_temp("available",1);
	setup();
}

void init()
{
	add_action("do_move", "move");
}

int do_move(string arg)
{
//	string dir;
	object me,ob;

	if( !arg || arg=="" || !query_temp("available") ) return 0;

	if( arg=="daocao" && query_temp("available")) {
		write("你試著把稻草慢慢移開，突然發現下面埋著個身受重傷的男人 !\n\n");
	        delete_temp("available");
	}


	me = new(__DIR__"npc/wanyan",1);
	me->move(__DIR__"mafang");

	ob = this_player();	

	me->unconcious();

	remove_call_out("fainting");
	call_out("fainting", 100, me, ob);

	return 1;
}

void fainting(object me, object ob)
{
        message_vision("完顏洪烈緩緩甦醒了過來，說道: 救、、我、、\n",ob);
        me->revive();
	
	return;
}

string look_daocao()
{
	return "這是一大堆稻草，堆在牆腳邊，不知是派什麼用場。\n";
}

