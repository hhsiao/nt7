// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "森林");
	set("long", @LONG
這裡四周是是參天古木，中間卻有一眼清泉，你不由的大喜過往。北面樹
林越發的緊密，很難深入。?
LONG
	);
        set("outdoors", "大理");

	set("exits", ([
            "east" : __DIR__"shanlin-4",
	    "north" : __DIR__"shanlin-6",
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
            message("vision", me->name()+"趴在泉邊用手捧了一些水喝。\n"
            , environment(me), ({me}) );
            write("你喝了一口清涼的泉水，覺得舒服多了。\n");
        }
        else write("喝那麼多的涼水，你不怕生病嗎?\n");
        return 1;
}