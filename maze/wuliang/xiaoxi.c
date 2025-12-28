// xiaoxi.c
// bbb 1997/06/11
// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "山中小溪");
        set("long", @LONG
在山路的旁邊了出現一條小溪。周圍安靜極了，只聽見小河流水在孱孱作
響。一些口渴的行人在溪邊喝水，遠處好象有一些看不清模樣的動物也在溪裡
玩鬧。南面是一條上山的路，正北面都是荊棘和矮草灌木，走在裡面一定會劃
傷身體，依稀有一條小路通向深處。
LONG
        );
        set("resource/water", 1);

        set("exits", ([
             "north" : __DIR__"shanlu8",                
	     "southwest" : "/d/dali/shanlu3",
             "southup" : __DIR__"shanlu5",
        ]));
        set("outdoors", "大理");
        set("objects", ([
//            __DIR__"obj/yeguo" : 2,
        ]));

        set("coor/x",-300);
  set("coor/y",-300);
   set("coor/z",-20);
   setup();
}

void init()
{
        add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        int current_water;
	int max_water;
        object me;

        me = this_player();
        current_water=query("water", me);
        max_water=query("str", me)*10+100;
        if (current_water<max_water) {
            set("water", current_water+30, me);
            message("vision", me->name()+"趴在溪邊用手捧了一些水喝。\n"
            , environment(me), ({me}) );
            write("你喝了一口從山上流淌下來的溪水，覺得舒服多了。\n");
        }
        else write("喝那麼多的涼水，你不怕生病嗎?\n");

        return 1;
}

int valid_leave(object me, string dir)
{
        if(dir=="north" ){
        if( query("can_ride", me)){
          return 0;
          }       
        if( query_temp("ride_horse", me) )
        return notify_fail("你不怕荊棘和矮草灌木傷了馬匹。\n");
        }
        return ::valid_leave(me, dir);
}