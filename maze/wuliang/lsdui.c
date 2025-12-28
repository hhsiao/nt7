// Room: lsdui.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "亂石堆");
        set("long", @LONG
你片刻間轉過山坳，只見一大堆亂石之中團團坐著二十餘人。人叢中一個
瘦小的老者坐在一塊高巖之上，高出旁人。
LONG
        );
        set("exits", ([ 
            "southwest" : __DIR__"xiaolu2",
        ]));
        set("objects", ([
                __DIR__"npc/sikong_xuan" : 1, 
        ]));
        set("outdoors", "大理");

        setup();
}
