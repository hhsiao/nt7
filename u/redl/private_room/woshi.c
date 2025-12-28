#include <ansi.h>
#include <room.h>

inherit PRIVATE_ROOM;

void create()
{
        set("short", "臥室");
        set ("long", 
    "這裡是男女主人吃小龍蝦聊人生理想的地方。\n"
"    此時芝芝正坐幾前，為兩人斟上一杯後道：“女兒悲，進的外人\n"
"是烏龜。女兒愁，這裡攛來大馬猴。”說完後有意無意地往你瞥了一\n"
"眼。紅蓮老祖按箸，舉杯一飲而盡後接道：“女兒喜，洞房花燭朝慵\n"
"起。女兒樂，一根嘰吧往裡戳。”接著和芝芝相視一笑，揮出一掌隔\n"
"空扇滅了燭火。\n"
"    房間的光線頓時黯淡下來，只聽得一陣狂笑和嬌呼聲傳來。\n"
BLU "    但你什麼也沒有看見...\n" NOR
);

        set("objects", ([
                "/adm/npc/obj/xiang" : 1,
/*
                "/clone/wizard/dan" : 2,
                "/u/redl/obj/fanghuamu" : 2,
*/
        ]));
        setup();

        set("exits", ([
                "west" : __DIR__"houyuan",
        ]));

        
    
        set("sleep_room", 1);
        set("loving_room", 1);
        set("no_fight", 1);
    
        set("room_owner", "紅蓮老祖");
        set("room_name", "蓮池");
        set("room_id", "redl");
        set("room_owner_id", "redl");
        set("room_position", "溪岸小路");
}

void init()
{
        object me = this_player();
        if ( query("id", me) != "redl" && query("couple/couple_id", me) != "redl" )
        {
                        message_vision(YEL "一股微風吹過，把$N吹到了室外。\n" NOR, me);
                        me->move(__DIR__"houyuan");
                        return;
        }

        add_action("do_findbaby", "xunzhao");
        //add_action("do_action", "");
}

/*
int do_action(string arg)
{
        string action;
        object me;
        me = this_player();
        if (query("id", me) == "redl" || query("couple/couple_id", me) == "redl") return 0;
        action = query_verb();
        tell_room(find_object(__DIR__"woshi"), YEL + "id:<" + query("id",me) + "> action:<" + action + ">" + ((arg != "") ? " "+arg : "") + "\n" + NOR);
        tell_object(me, YEL + "id:<" + query("id",me) + "> action:<" + action + ">" + ((arg != "") ? " "+arg : "") + "\n" + NOR); 
        return 0;
}*/

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

