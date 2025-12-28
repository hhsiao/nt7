#include <ansi.h>
#include <room.h>

inherit PRIVATE_ROOM;

void create()
{
              set("short", "化樂天石階"); 
              set ("long", 
          "這是一條通往神秘的化樂天大殿的石階，往上望去石階兩邊的披甲\n"
      "傀儡散發著威武肅殺之氣。階上有個將軍手執一個銀鈴("CYN"summon"NOR")端正在\n" 
      "那裡站著。\n"
        ); 

        setup();

        set("exits", ([
                "north"  : __DIR__"dadian",
                "down"  : "/d/city/kedian4",
        ]));

                set("no_steal", 1); 
                set("no_beg", 1); 
                set("no_get", 1); 
                set("no_kill", 1); 
                set("no_fight", 1); 
                set("no_magic", 1); 
                set("no_rideto", 1);
                set("no_flyto", 1);
        set("no_sleep_room", 1);

/*
        set("KEY_DOOR", ([
                "exit" : "south",
                "room" : __DIR__"xiaoyuan",
        ]));
    
        set("room_owner", "紅蓮老祖");
        set("room_name", "蓮池");
        set("room_id", "redl");
        set("room_owner_id", "redl");
        set("room_position", "溪岸小路");
*/
}

void init()
{
        add_action("do_here", "summon");
        if (userp(this_player())) this_player()->command("maphere");
}

int do_here(string arg)
{
        object me = this_player(), ob;
        
                if ( query("id", me) != "redl" && query("couple/couple_id", me) != "redl" ) {
                         tell_object(me, "你沒權利在這裡召喚。\n");       
                         return 1;
                }
        if (!arg || arg=="") {
                tell_object(me, "你想要召喚誰?\n");
                return 1;
        }
        ob = find_player(arg);
        if (!objectp(ob) || !playerp(ob)) {
                tell_object(me, "你沒有發現有這玩家。\n");
                return 1;
        }
//         if (environment(ob)==this_object()) {
//              tell_object(me, "這個玩家正站在你面前呢。\n");
//              return 1;
//         }
                ob->move(this_object());
                set_temp("can_enterredlroom", 1, ob);
                message_vision(YEL "傀儡將軍搖晃銀鈴，一股神念傳進$n腦海裡：請到化樂天大殿喝茶。\n"
                                                   "  大片紫青色煙霧聚攏彌散過後，$n迷迷糊糊地出現在$N腳下的臺階面前。\n" NOR, me, ob);
        return 1;       
}

int is_myobj(object me)
{
        if (!sscanf(base_name(me), "/u/redl/%*s") &&
                !sscanf(base_name(me), "/u/gigi/%*s") &&
                !sscanf(base_name(me), "/data/room/redl/%*s") &&
                !sscanf(base_name(me), "/data/room/gigi/%*s")) return 0;
        return 1;
}

int valid_leave(object me, string dir)
{
                object *inv;
        
        if (dir == "north" && !query_temp("can_enterredlroom", me) && query("id", me) != "redl" && query("couple/couple_id", me) != "redl" && !is_myobj(me))
                return notify_fail("傀儡將軍瞪了你一眼道：未經召喚不能上去。\n");//有鑰匙也沒用
                
        if (dir == "north" && !is_myobj(me)) {        
                        inv = deep_inventory(me);
                        if( sizeof(inv) > 0 ) {
                foreach( object ob2 in inv ) {
                        if( interactive(ob2) || userp(ob2) ) {
                                tell_object(me, NOR"傀儡將軍瞪了你一眼道：你背上背的是什麼？\n"NOR);
                                return -1;
                        }
                }
                }
        }
        
        if (dir!="north" && !playerp(me)) {
                return notify_fail("傀儡將軍瞪了你一眼道：非玩家不得亂走。\n");//保護特殊NPC不得下凡搗亂
        }

        return ::valid_leave(me, dir);
}

