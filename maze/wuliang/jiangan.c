// Room: jiangan.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "江岸");
        set("long", @LONG
江岸盡是山石，小路也沒一條，七高八低的走出七八里地，見到一株野生
桃樹，樹上結實累累。又走了十餘裡，才見到一條小徑。沿著小徑行去，終於
見了過江的鐵索橋，只見橋邊石上刻著“善人渡”三個大字。 
LONG
        );
        set("exits", ([
            "north" : __DIR__"tiesuo",
            "west" : __DIR__"anbian1",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "大理");

        set("coor/x",-280);
  set("coor/y",-290);
   set("coor/z",-20);
   setup();
}