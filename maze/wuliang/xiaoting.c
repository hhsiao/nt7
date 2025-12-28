// Room: xiaoting.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "小廳");
        set("long", @LONG
一間雅緻的小廳，桌上點著一對巨燭，東壁上有四幅屏條，繪的是梅蘭竹
菊，可是順序卻掛成了蘭竹梅菊，西壁上的春夏秋冬，則掛成了冬夏春秋。看
來此間主人必是個武人。
LONG
        );
        set("exits", ([
            "east" : __DIR__"guzhong",           
        ]));

        set("objects", ([
            __DIR__"npc/zhong_ling" : 1,
        ]));

        setup();
}