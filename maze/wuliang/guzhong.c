// Room: guzhong.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "萬劫谷");
        set("long", @LONG
你來到了萬劫谷內，對面不遠處是幾間瓦房，左首邊另有一間小瓦房。兩
邊的山壁很陡峭，看來是沒法上下的。谷中一條小路繞過正面的房舍通往谷後，
不知去向什麼地方。
LONG
        );
        set("exits", ([
            "north" : __DIR__"xiaojing",
            "south" : __DIR__"keting",
            "west" : __DIR__"xiaoting",
        ]));

        set("objects", ([
              __DIR__"npc/laifu_er" : 1,
              __DIR__"npc/jinxi_er" : 1,
        ]));
        
        set("outdoors", "大理");

        setup();
}