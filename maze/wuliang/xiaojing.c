// Room: xiaojing.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "谷中小徑");
        set("long", @LONG
你走在谷中的一條小徑上，這裡十分荒僻，頭頂有一些不知名的小鳥在跳
來跳去，四周叢林密佈，鮮花綠草若隱若現。
LONG
        );
        set("exits", ([
            "north" : __DIR__"caodi",
            "south" : __DIR__"guzhong",
        ]));
        
        set("outdoors", "大理");

        setup();
}