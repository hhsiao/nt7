#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "蕩天門");
        set("long",@LONG
過了此門，便是三元宮、兜率大士院等寶殿。抬頭望去，只見屋宇連
綿，輕煙繚繞，傳來一陣陣誦經、木魚之聲。這裡南面是睡房，供給天龍
俗家弟子休息之用，門口掛著一個牌子(pai)，左右各站著一位武僧。
LONG
        );
	set("outdoors","dali");
        set("exits", ([    			
                "west" : __DIR__"3wg",
                "east" : __DIR__"yz5",
               "south" : __DIR__"xiuxishi2",
               	]));
        set("objects",([
                __DIR__"npc/wuseng" : 2,
        ]));
                                                    
        set("item_desc",([
           "pai" : "南面為天龍俗家弟子睡房。\n"NOR,
        ]));
       
        create_door("west", "木門", "east", DOOR_CLOSED);

        set("coor/x",-380);
  set("coor/y",-320);
   set("coor/z",20);
   setup();
}
int valid_leave(object me, string dir)
{
        if (me->query("family/family_name") != "天龍寺" &&
            present("wu seng", environment(me)) && dir =="south")
           return notify_fail("武僧攔住你的去路，抱拳道：非天龍俗家弟子不得入睡房。\n");
        if ((me->query("class") =="bonze") && dir =="south" )
           return notify_fail("你是出家人，去到那俗家弟子睡放幹嘛？\n");                
        return ::valid_leave(me, dir);
}
