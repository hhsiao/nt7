inherit ROOM;

void create()
{
        set("short", "靈塔林");
        set("long",@LONG
走出了小路，眼前豁然一亮，這是一片塔林。放眼望去，林林總總
有不下百座高矮不一的石塔，這些都是歷代高僧圓寂後，為他們修的
靈塔。這裡冷冷清清，不時傳來幾聲野獸的嗥叫，走在塔林中，你的
心中不免有些害怕。
LONG
        );
        set("outdoors", "tianlongsi");
        set("exits", ([
		"east" : __DIR__"shanlu-4",
        ]));
//	set("objects",([
//                __DIR__"npc/saodiseng" : 1,
//        ]));
        set("coor/x",-460);
  set("coor/y",-320);
   set("coor/z",30);
   setup();
}
