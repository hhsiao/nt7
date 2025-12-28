// Modify By River 98/12
inherit ROOM;
void create()
{
	set("short", "石屋");
	set("long", @LONG
眼前是一個石屋。這石屋模樣甚是奇怪，以一塊千百斤重的大石砌成，凹
凹凸凸，宛然是一座小山，洞口被一塊花崗巨巖（yan)封住，巖邊到處露出空
隙，有的只兩三寸寬，有的卻有尺寬。?
LONG
	);
        set("outdoors", "大理");

	set("exits", ([
		"south" : __DIR__"muwu1",
	]));

        set("item_desc", ([
            "yan" : "這是一塊特別大的岩石，堵住了門口，使人無法進入屋內。\n",
        ]));

        setup();
}

void init()
{
        add_action("do_tui", "tui");
        add_action("do_tui", "push");
}

int do_tui(string arg)
{
        int i;
        i=query("neili", this_player());
        if( !arg || arg!="yan" ) 
           return notify_fail("你要推什麼？\n");        
          message_vision("$N站在門前，把雙掌放在巖上，深深的吸了一口氣，雙臂一發勁，大喝一聲“開”。\n", this_player());
        if (i>=800) {
          message_vision("$N只聽一陣轟響，大石緩緩的移開了！\n", this_player());
          set("exits/enter", __DIR__"muwu3");
          addn("neili", -800, this_player());
          remove_call_out("close");
          call_out("close", 5, this_object());
          }
        else {
          message_vision("$N卻見大石紋絲不動，看來$N的內力還不夠。\n", this_player());
          set("neili", 0, this_player());
          }
    return 1;
}

void close(object room)
{
         message("vision","大石緩緩移動，把石屋再次封住了。\n", room);
         delete("exits/enter", room);
}