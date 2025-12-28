// File(/data/room/buga/woshi.c) of buga's room
// Create by LUBAN written by Doing Lu

#include <room.h>
#include <ansi.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "蟲洞臥室");
	set ("long", @LONG
這是主人的臥室，收拾得井井有條。南窗下是一張大床，床邊有
一個櫃子，還有一個書架，上面放著一些書。整間屋子佈置得非常樸
素，並不奢華。屋門在西首。 
LONG );

        set("objects", ([
                "/adm/npc/obj/xiang" : 1,
        ]));
        setup();

        set("exits", ([
                "west" : __DIR__"dating",
        ]));

        create_door("west", "木門", "east", DOOR_CLOSED);
        
    
        set("sleep_room", 1);
        set("loving_room", 1);
        set("no_fight", 1);
    
        set("room_owner", "紅臭蟲");
        set("room_name", "蟲洞");
        set("room_id", "bugaa");
        set("room_owner_id", "buga");
        set("room_position", "碎石小道");
}

void init()
{
        add_action("do_findbaby", "xunzhao");
}

int do_findbaby(string arg)
{
        object me = this_player(), baby;
        string file;

        if (! arg || (arg != "baby" && arg != "child") ||
            ! is_room_owner(me)) 
                return 0;

        if( !query("couple/child_id", me) )
                return notify_fail("你又還沒有孩子，來這裡湊什麼熱鬧啊？\n");

        if( objectp(baby=find_living(query("couple/child_id", me)) )
        &&  environment(baby) && baby->is_baby())
                return notify_fail("你們的孩子已經跑出去玩了，好好四處找找吧！\n");

        if( query("gender", me) == "女性" )
                file=read_file("/data/baby/"+query("id", me)+".o");
        else file=read_file("/data/baby/"+query("couple/couple_id", me)+".o");

        if (stringp(file))
        {
                baby = new("/clone/user/baby");

                baby->load_baby(me);
                baby->move(environment(me));
                message_vision("你忽然看到床底下" +
                        ({"探出一顆小腦瓜", "伸出一雙小腳丫", "伸出一支小手"})
                        [random(3)] + "．．．\n", me);

        } else
        {
                tell_object(me, MAG "你們的孩子不幸夭折了，請節哀吧。\n" NOR);
                delete("couple/child_id", me);
                delete("couple/child_name", me);
        }
        return 1;
}      
