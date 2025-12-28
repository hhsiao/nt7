
inherit ROOM;
void create()
{
	set("short", "月影樓");
	set("long", @LONG
此處群牆下面是白石臺階，雕成朵朵蓮花模樣，
屋子裡是大理石砌成紋理，顯得富麗而又不落俗套。
LONG    );
	set("exits", ([ 
  "up" : __DIR__"yyl1",
  "northdown" : __DIR__"froom1",
  "southdown" : __DIR__"qfg",
]));
        set("objects",([
                        __DIR__"npc/guards3" : 1,
       	]) );
	set("coor/x",-30);
	set("coor/y",1140);
        set("coor/z",70);
	setup();
}
int valid_leave(object me, string dir)
{
        if (  (dir == "up")
 &&((string)me->query("class") != "bandit") 
//  && ((string)me->query("family/family_name") != "圓月山莊")
           && objectp(present("guards", environment(me))) )
        return notify_fail("守衛擋住你道；非本莊第子不得擅闖月影樓！。\n");
        return ::valid_leave(me, dir);
}
