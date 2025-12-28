
inherit "/inherit/room/house_base";

void create()
{
    set("short", "山間草地");
    set("long", @LONG
此間位於石經峪西側。放眼望去，一片青翠之中點綴著星星點點
的野花，或粉白或蕊黃或奼紫或嫣紅，煞是好看。一座黛瓦粉牆的山
莊設在草地一頭，好像是江湖中哪個幫會的駐地所在。
LONG);

    set("exits",
    ([
        "east"  : "/d/taishan/shijin",
    ]));

    set("outdoors", "taishan");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
