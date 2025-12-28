inherit ROOM;

void create()
{
        set("short", "漁村曬網場");
        set("long", @LONG
小村不大，卻有個好大的曬網場。幾個小孩在場中無憂地玩耍，
聲音喧鬧。靠南海邊上，有個漁夫面向大海，悠然垂釣。
LONG );
        set("outdoors", "nanhai");
        set("exits", ([
                "out"    : "/d/xiakedao/haibin",
        ]));
        set("objects", ([
                CLASS_D("misc/haigui") : 1,
        ]));
        set("coor/x", -1390);
        set("coor/y", -9000);
        set("coor/z", 0);
        setup();
}
