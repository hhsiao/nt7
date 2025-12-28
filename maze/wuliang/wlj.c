// Room: wlj.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "石板路");
	set("long", @LONG
你走在一條寬闊的石板路上。這是用一米見方的巨大石板鋪設而成的，可
以並行十來個人也絕無問題。兩側是參天古柏，直聳入天，上端樹冠相疊，遮
天蔽日。路的盡頭，就是劍湖宮了。
LONG
	);
	set("exits", ([ 
	    "out" : __DIR__"wljmen",
	    "north" : __DIR__"jhg",
            "west" : __DIR__"xting",
            "east" : __DIR__"dting",
        ]));
        set("objects", ([
              __DIR__"npc/rong_ziju" : 1, 
        ]));
        set("outdoors", "大理");

	setup();
}

int valid_leave(object me,string dir)
{ 
     if( dir != "out"
      && (present("rong ziju", environment(me))))
         return notify_fail("容子矩上前攔住你的去路：無量劍重地，任何人不得擅自入內。\n");
         return ::valid_leave(me, dir);
}