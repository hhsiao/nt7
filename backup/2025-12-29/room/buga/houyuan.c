// File(/data/room/buga/houyuan.c) of buga's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "蟲洞後院");
	set ("long", @LONG
這是蟲洞的後院，種著一些花草，大部分是都不知名的野生花草。
不過花兒開起來也看上去也非常漂亮。有時紅臭蟲讀書練武疲倦了，
就到這裡稍作片刻以休息，也有時友人來到這裡，大家在這裡切磋一
下武藝。 
LONG );

        setup();

        set("exits", ([
                "south"  : __DIR__"dating",
        ]));

        set("outdoors", "playertown");
        set("sleep_room", 1);

        set("room_owner", "紅臭蟲");
        set("room_name", "蟲洞");
        set("room_id", "bugaa");
        set("room_owner_id", "buga");
        set("room_position", "碎石小道");
}

void init()
{
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
