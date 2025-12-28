// Room: jhg.c
// By River 98/12
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIY"劍湖宮"NOR);
	set("long", @LONG 
宮內坐著二人，上首是個四十左右的中年道姑，下首是個五十餘歲的老者。
西首錦凳上所坐的則是別派人士，其中有的是東西二宗掌門人共同出面邀請的
公證人，其餘則是前來觀禮的嘉賓。這些人都是雲南武林中的知名之士。
LONG
	);
	set("exits", ([ 
	    "south" : __DIR__"wlj",
	    "north" : __DIR__"houyuan",
            "west" : __DIR__"xlgong",
            "east" : __DIR__"dlgong",
        ]));
        set("objects", ([
                __DIR__"npc/zuo_zimu" : 1,
                __DIR__"npc/xin_shuangqing" : 1,
                __DIR__"npc/gong_guangjie" : 1, 
        ]));

	setup();
}

int valid_leave(object me,string dir)
{ 
     if( dir != "south"
      && (present("gong guangjie", environment(me))))
         return notify_fail("龔光傑上前攔住你的去路：無量劍重地，任何人不得擅自入內。\n");
     if( dir != "south"
      && (present("xin shuangqing", environment(me))))
         return notify_fail("辛雙清上前攔住你的去路：無量劍重地，任何人不得擅自入內。\n");
     if( dir != "south"
      && (present("zuo zimu", environment(me))))
         return notify_fail("左子穆上前攔住你的去路：無量劍重地，任何人不得擅自入內。\n");
         return ::valid_leave(me, dir);
}