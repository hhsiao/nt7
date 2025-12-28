inherit ROOM;

void create()
{
          set("short", "山間平臺");
        set("long", @LONG
這是失足巖左側的一塊大平臺，平臺周圍聚滿了人。左邊通向靈
鷲宮的必經之路，山道被一塊鷹喙突出的巨巖截斷，巨巖光可鑑人，
只有中間一條窄窄的石階通向山道的那一頭。
LONG );
        set("outdoors", "lingjiu");
        set("exits",([
                "west" : __DIR__"shandao",
        ]));
        set("objects",([
                // CLASS_D("lingjiu") + "/li" : 1,
                CLASS_D("lingjiu") + "/sang" : 1,
        ]));

        setup();
        replace_program(ROOM);
}