// File(/data/room/ovo/huayuan.c) of ovo's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "後花園");
	set ("long", @LONG
這是東北偏北的後花園，種著一些小球球採自五湖四海、名山大
川的奇花異草，美麗非常。小球球有時讀書練武疲倦了，就到這裡稍
作休息，觀賞花草以怡情自樂，或許能突發靈感，有所領悟。西面就
是通往主人居所的鐵門，東面則是一片竹林。 
LONG );

        set("exits", ([
                "north"  : __DIR__"caidi",
                "south"  : __DIR__"houyuan",
                "east"   : __DIR__"zhulin",
        ]));

        set("outdoors", "playertown");
        set("sleep_room", 1);
        set("room_key", "1 of ovo");
        setup();

        set("KEY_DOOR", ([
                "exit" : "west",
                "room" : __DIR__"jusuo",
        ]));
    
        set("room_owner", "小球球");
        set("room_owner_id", "ovo");
        set("room_name", "東北偏北");
        set("room_id", "dan");
        set("room_position", "碎石小道");
}

void init()
{
        ::init();
        add_action("do_sit", "sit");
        delete_temp("has_sit", this_player());
}

int do_sit(string arg)
{
        object me;

        me = this_player();
        if( query_temp("has_sit", me) )
        {
                message_vision("$N坐在那裡搖啊搖，好不愜意。\n", me);
                return 1;
        }

        message_vision("$N找了的地方作了下來，看上去輕鬆多了。\n", me);
        set_temp("has_sit", 1, me);
        return 1;
}

int valid_leave(object me, string dir)
{
        if( query_temp("has_sit", me) )
        {
                message_vision("$N撣撣塵土，站了起來。\n", me);
                delete_temp("has_sit", me);
        }

        return ::valid_leave(me, dir);
}
