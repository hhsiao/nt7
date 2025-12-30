// File(/data/room/wwcha/dulewu.c) of wwcha's room
// Create by LUBAN written by Doing Lu
#include <ansi.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "我的小屋");
	set ("long", @LONG
屋子不大，靠窗的地方擺了一張床，屋中一張桌，幾隻椅，非常
簡單。看來主人是一個甘於平淡寂寞的人。 
LONG );

        set("objects", ([
                "/adm/npc/obj/xiang" : 1,
        ]));
        setup();

        set("KEY_DOOR", ([
                "exit" : "south",
                "room" : __DIR__"xiaoyuan",
        ]));
    

        set("sleep_room", 1);
        set("loving_room", 1);
        set("no_fight", 1);
    
        set("room_owner", "大波龍");
        set("room_name", "我的");
        set("room_id", "popo");
        set("room_owner_id", "wwcha");
        set("room_position", "山洪瀑布");
}

void init()
{
        ::init();
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
