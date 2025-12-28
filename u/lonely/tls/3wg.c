#include <room.h>

inherit ROOM;

void create()
{
        set("short", "三無宮");
        set("long",@LONG
無住、無相、無願便是佛家常說的‘三無’。這寶座上坐的是南
無彌勒尊佛金像，開懷露腹，笑看眾生。幾個知客僧人正來往忙碌招
待香客。北面通往兜率大士院，南面是一條石板路。西面通向龍象臺。
LONG);
        set("exits", ([
                "east" : __DIR__"men4",
		"northup" : __DIR__"shiyuan",  
                "westup" : __DIR__"longxiang1",            
	]));
	
        create_door("east", "木門", "west", DOOR_CLOSED);

        set("coor/x",-390);
  set("coor/y",-320);
   set("coor/z",20);
   setup();
}
