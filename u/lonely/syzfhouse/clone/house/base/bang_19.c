
inherit "/inherit/room/house_base";

void create()
{
    set("short", "南湖柳岸");
    set("long", @LONG
這裡是南湖水岸，湖畔柔柳如煙。獨立柳下可見南湖旖旎風光。
最是陰雨天氣，煙靄似紗，雨絲如霧。岸邊不遠處有一處青瓦粉牆的
嶄新大院，好像是江湖某個幫會的駐地所在。
LONG);

    set("exits",
    ([
        "south"  : "/d/fuzhou/nanhu1",
    ]));

    set("outdoors", "fuzhou");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
