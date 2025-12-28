// Room: xiaolu2.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "青石小路");
	set("long", @LONG
這是由青石鋪成的小路，路面上夾雜著一些泥沙，小路兩邊長著一些野草，
開出來的野花飄著陣陣花香。四周是陰森森的原始老林，不時傳來一陣陣的野
獸叫聲, 頭頂有一些不知名的小鳥在跳來跳去。
LONG
	);
	set("exits", ([ 
	    "northup" : __DIR__"xiaolu3",
            "northeast" : __DIR__"lsdui",
	    "westdown" : __DIR__"xiaolu1",
        ]));

        set("outdoors", "大理");

	set("coor/x",-280);
  set("coor/y",-310);
   set("coor/z",10);
   setup();
}