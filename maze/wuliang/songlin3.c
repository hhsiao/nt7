// Room: songlin3.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "大松林");
	set("long", @LONG
你眼前驟然一黑，朦朧中，只見左右前後，到處都是鋪天蓋地的松樹林。
幾十丈高的大松樹簇在一塊，密實的枝葉象一蓬蓬巨傘般伸向天空，把陽光遮
得絲毫也無。尺把厚的松針積在地上，一腳踩下去，半天拔不出來。你似乎迷
失了方向，象沒頭蒼蠅般到處亂闖。
LONG
	);
	set("exits", ([ 
	    "south" : __DIR__"songlin"+(1+random(6)),
            "north" : __FILE__,
            "east" : __DIR__"songlin"+(1+random(6)),
            "west" : __DIR__"songlin"+(1+random(6)),
        ]));
        set("outdoors", "大理");
	setup();
}

void reset()
{
	set("exits", ([ 
		"south" : __DIR__"songlin"+(1+random(6)),
		"north" : __FILE__,
		"east" : __DIR__"songlin"+(1+random(6)),
		"west" : __DIR__"songlin"+(1+random(6)),
        ]));
}