// Room: caodi.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "萬劫谷谷口");
        set("long", @LONG
眼前大片草地，盡頭處又全是一株株松樹。走過草地，只見一株大松上削
下了丈許長、尺許寬的一片，漆上白漆，寫著九個大字：“姓段者入此谷殺無
赦”。八字黑色，那“殺”字卻作殷紅之色。 
LONG
        );
        set("exits", ([
            "out" : __DIR__"hslin",
            "south" : __DIR__"xiaojing",
        ])); 
        set("outdoors", "大理");

        setup();
}