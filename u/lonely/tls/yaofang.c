//yaofang.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", GRN"藥房"NOR);
	set("long", @LONG
這裡是天龍寺的藥房，房間裡瀰漫著濃濃的藥香，房間內排滿了裝滿各類
藥材的大藥櫃，每個藥櫃都有上百個裝藥的抽屜貼滿了各類藥名。西邊是一個
巨大紅杉木櫃，櫃上貼著方丈印的封條。一位中年僧人正來回忙碌著指點眾執役
僧稱量藥品，熬藥煎湯。
LONG
	);
 set("exits", ([
             "north" : __DIR__"yaotai", 
        ]));

         set("objects",([
		 __DIR__"npc/liao-ming" : 1,
	]));

	
	set("coor/x",-310);
  set("coor/y",-330);
   set("coor/z",30);
   setup();
}



