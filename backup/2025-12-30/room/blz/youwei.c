// File(/data/room/blz/youwei.c) of blz's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        object ob;

        set("short", "逍遙洞右衛舍");
	set ("long", @LONG
這裡是右衛舍，是看護逍遙洞大門的家丁放哨的地方。 
LONG );

        set("exits", ([
                "east"   : __DIR__"qianting",
        ]));

        set("objects", ([
                "/d/room/roomnpc/shouwei" : 2,
        ]));

        set("no_sleep_room", 1);
        setup();

        ob = present("shou wei", this_object());
        ob->set("coagents", ({
                ([ "startroom" : __DIR__"youwei",
                   "id"        : "shou wei 1" ]),
                ([ "startroom" : __DIR__"youwei",
                   "id"        : "shou wei 2" ]),
                ([ "startroom" : __DIR__"zuowei",
                   "id"        : "shou wei 2" ]),
                ([ "startroom" : __DIR__"zuowei",
                   "id"        : "shou wei 1" ]),
        }));

        ob = present("shou wei 2", this_object());
        ob->set("coagents", ({
                ([ "startroom" : __DIR__"youwei",
                   "id"        : "shou wei 1" ]),
                ([ "startroom" : __DIR__"youwei",
                   "id"        : "shou wei 2" ]),
                ([ "startroom" : __DIR__"zuowei",
                   "id"        : "shou wei 2" ]),
                ([ "startroom" : __DIR__"zuowei",
                   "id"        : "shou wei 1" ]),
        }));

        set("room_owner", "暴雪");
        set("room_name", "逍遙洞");
        set("room_id", "blz");
        set("room_owner_id", "blz");
        set("room_position", "青磚路");
}
