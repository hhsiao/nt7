// cool 98.3.17
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "無量山峰");
	set("long", @LONG
這裡是無量山的高峰上，寂靜無人。只聽山峰下轟隆、轟隆，奔騰澎湃的
水聲不斷傳來，你向下看，但見瀾滄江浩浩蕩蕩的從山腳下湧過，煞是壯觀。
西面山下是江邊，南面是來時候的森林。
LONG
	);
        set("outdoors", "大理");
	set("exits",([
             "south" : __DIR__"shanlu12",
             "westdown" : __DIR__"anbian",	
	]));

        set("objects", ([
	      __DIR__"obj/yeguo" : 2,
	]));
	setup();
}