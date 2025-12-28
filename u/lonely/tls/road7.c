//road7.c

inherit ROOM;

void create()
{
        set("short", "石板路");
        set("long", @LONG
    你走在一條長長的石板路上，道旁古樹參天，鳥鳴不絕，前面是
一片大松林，這條路一直通向松林深處，林子裡黑黑漆漆的，你不由的默
念“阿彌陀佛”。
LONG    );
        set("exits", ([ /* sizeof() == 2 */
   "north" : __DIR__"songlin-1",
  "south" : __DIR__"yuhua1",

   
]));
        set("no_clean_up", 0);
        set("outdoors", "天龍寺");

        setup();
}
