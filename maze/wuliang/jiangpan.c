// jiangban.c
// bbb 1997/07/20
// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "江畔");
	set("long", @LONG
外邊怒濤洶湧，水流湍急，江岸山石壁立，嶙峋巍峨，看這情勢，已是到
了瀾倉江邊，容身處離講面有十來丈高，江水縱然大漲，也不會淹到此處江岸
全是山石。
LONG
	);

	set("exits", ([
           "enter" : __DIR__"taijie",
           "down" : __DIR__"anbian1",
	]));
        set("outdoors", "大理");
	setup();
}