inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
    你走在一條長長的石板路上，道旁古樹參天，鳥鳴不絕，這條
路上冷冷清請，你走了好長時間，也看不見一個人。
LONG	);
	set("exits", ([ /* sizeof() == 2 */
   "west" : __DIR__"shanlu-3",
  "east" : __DIR__"shanlu-1",

   
]));
	set("no_clean_up", 0);
	set("outdoors", "tianlongsi");

	set("coor/x",-430);
  set("coor/y",-320);
   set("coor/z",30);
   setup();
}
