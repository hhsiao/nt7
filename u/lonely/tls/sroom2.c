inherit ROOM;

void create()
{
        set("short", "休息室");
        set("long", @LONG
這是間僧人們的睡房，因門窗常閉著，光線很昏暗，靜靜的，只
有微微的酣聲。房裡別無他物，非常簡樸，靠牆擺著很多張木板床，
你悄悄的走過去，找了張空床躺了下來。
LONG);
        set("exits", ([
               "south" : __DIR__"road4",
               "west" : __DIR__"sroom",
        ]));
        set("no_fight",1);
        set("sleep_room", 1);
        set("coor/x",-340);
  set("coor/y",-270);
   set("coor/z",30);
   setup();
}




