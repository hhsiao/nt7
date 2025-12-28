// Room: 山路 5
// bbb 1997/06/11
// Modify By River 98/12
inherit ROOM;
void create()
{
        set("short", "無量山路");
	set("long", @LONG
你正走在一條崎嶇不平的路上,四周是陰森森的原始老林,不時傳來一陣陣
的野獸叫聲, 頭頂有一些不知名的小鳥在跳來跳去。東邊一條山路向上延伸，
不知道通向哪裡。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	    "eastup" : __DIR__"xiaolu1",
	    "northdown" : __DIR__"xiaoxi",
        ]));
	set("no_clean_up", 0);
        set("outdoors", "大理");

	set("coor/x",-300);
  set("coor/y",-310);
   set("coor/z",-10);
   setup();
}

int valid_leave(object me, string dir)
{
        if(dir=="eastup" ){
        if( query("can_ride", me)){
          return 0;
          }       
        if( query_temp("ride_horse", me) )
        return notify_fail("上山不宜騎馬。\n");
        }
        return ::valid_leave(me, dir);
}