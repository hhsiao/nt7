// Room: pubu.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "大瀑布");
	set("long", @LONG
你又奔出一陣，雙腿痠軟，氣喘吁吁，終於走出了大松林。猛聽得水聲響
亮，轟轟隆隆，便如潮水大至一般，抬頭一看，只見西北角上猶如銀河倒懸，
一條大瀑布從高崖上直瀉下來。
LONG
	);
	set("exits", ([ 
	    "west" : __DIR__"songlin1", 
            "southeast" : __DIR__"shanya",
        ]));
        set("objects", ([
                __DIR__"npc/ge_guangpei" : 1,
                __DIR__"npc/gan_guanghao" : 1,
        ]));
        set("outdoors", "大理");

	setup();
}

int valid_leave(object me,string dir)
{ 
     if( dir == "southeast"
      && (present("gan guanghao", environment(me))))
         return notify_fail("幹光豪對你奸笑一聲：想逃，你留下命來吧。\n");
     if( dir == "southeast"
      && (present("ge guangpei", environment(me))))
         return notify_fail("葛光佩對你冷笑一聲：想逃，你留下命來吧。\n");
         return ::valid_leave(me, dir);
}