
inherit DEMONROOM;

void create()
{
        set("short", HIW"亂石路"NOR);
        set("long", @LONG
這裡是雁門關的亂石路, 是扼守南北的交通必經之路，歷來為兵家必
爭之地，由山頂幣制而下，只有一條狹窄的羊腸小道，兩面則是堆滿亂石，
好象暗浮殺機。
LONG
        );
        set("outdoors", "yanmen");
        set("exits", ([
                "north" :  __DIR__"luanshi2",
                "south" :  __DIR__"luanshi4",
        ]));
        set("no_fly",1);
        set("n_time", 30); 
        set("n_npc", 5); 
        set("n_max_npc", 15);
        set("s_npc", __DIR__"npc/qidanbing");

        setup();
}
