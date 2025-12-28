//  nanhubian.c 
// bbb 1997/06/11
// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "南湖邊");
        set("long", @LONG
這湖作橢園之形，大半部隱在花樹叢中，東南西北盡是懸崖峭壁，只有剛
爬下來的山坡比較最斜，其他各處決計無法攀上，湖畔生長著一叢叢的茶花，
搖夷生姿。湖水清澈，閃著銀光。
LONG
        );
        set("resource/water", 1);
        set("outdoors", "大理");
        set("exits", ([
                "northeast" : __DIR__"xihubian",
		"northwest" : __DIR__"beihubian",
                "north" : __DIR__"shulin3",
        ]));

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
            message("vision", me->name()+"趴在湖邊用手捧了一些水喝。\n"
            , environment(me), ({me}) );
            write("你喝了一口從山上瀑布流淌下來的湖水，甘美異常。\n");
        }
        else write("喝那麼多的涼水，你不怕生病嗎?\n");
        return 1;
}