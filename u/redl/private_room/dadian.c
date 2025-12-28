#include <ansi.h>
#include <room.h>

inherit PRIVATE_ROOM;

int clean_up() { return 1;} 

void create()
{
              set("short", "化樂天大殿"); 
              set ("long", 
          "這裡是男主人紅蓮老祖和女主人芝芝品茶和接待朋友的地方("CYN"sit"NOR")。\n"
      "側面是兩扇屏風，正中有些桌椅，上方懸掛一匾上書：\n" 
          "    " BBLU CYN "╔───────╤───────╗\n" NOR
          "    " BBLU CYN "┃" NOR BBLU HIC "把盞銜杯意氣深，兄兄弟弟抑何親" NOR BBLU CYN "┃\n" NOR
          "    " BBLU CYN "┃" NOR BBLU HIC "一朝平地風波起，此際相交才見心" NOR BBLU CYN "┃\n" NOR
          "    " BBLU CYN "╚───────╧───────╝\n" NOR


        ); 


        set("exits", ([
                   //"west"   : "/u/gigi/startroom",
                "north"  : "/u/redl/houdian",
                "south"  : __DIR__"dating",
        ]));

        set("objects", ([ 
                                "/u/redl/npc/queen" : 1, 
                                "/u/redl/obj/table" : 1,  
        ])); 

                set("no_fight", 1); 
                set("no_rideto", 1);
                set("no_flyto", 1);
        set("no_sleep_room", 1);

        setup();

        set("room_owner", "紅蓮老祖");
        set("room_name", "蓮池");
        set("room_id", "redl");
        set("room_owner_id", "redl");
        set("room_position", "溪岸小路");
}


void init()
{
        add_action("do_sit", "sit");
        delete_temp("has_sit", this_player());
}

int do_sit(string arg)
{
        object me;
        string sex;
        int tea = 50000;

        me = this_player();
        
        if (!query_temp("can_enterredlroom", me) && query("id", me) != "redl" && query("couple/couple_id", me) != "redl") return notify_fail("傀儡將軍對著你嘿嘿嘿奸笑了幾聲。\n");
        
        if ( me->is_busy() ) {
                        tell_object(me, "你還是忙完手頭上的事情再說吧。\n");
                        return 1;
                }
        me->start_busy(2);
        
        sex = query("gender", me);
        
        if( query_temp("has_sit", me) )
        {
                switch(random(7)) {
                        case 0:
                        case 1:
                        message_vision(CYN "$N默默地若有所思，前後搖了搖椅子。\n" NOR, me);
                        break;
                case 2:
                        case 3:
                        message_vision(CYN "$N輕輕伸手捂住嘴，小聲地咳嗽了幾聲。\n" NOR, me);
                        break;
                case 4:
                        case 5:
                        message_vision(CYN + ((sex=="男性")? "$N不知道想起了什麼事，裂開厚嘴唇呵呵笑了笑。\n" : "$N不知道想起了什麼事，眯著眼睛笑得像月牙兒。\n") + NOR, me);
                        break;
                default:
                        message_vision(CYN "$N端起桌上的靈芝蓮子茶，慢慢地送到唇邊抿了一口。\n" NOR, me);
                                        if ( !query_temp("has_drinkredltea", me) ) {
                                                call_other(GIFT_D, "bonus", me, ([ "exp":tea, "pot":tea/4, "mar":tea/10, "prompt":"你在喝下靈芝蓮子茶後"]));
                                message_vision(HIG "$N意猶未盡，“嘖嘖”地咂了幾下嘴巴。\n" NOR, me);
                                        }
                                        set_temp("has_drinkredltea", 1, me);//不quit後第二次再獲邀請來這裡，是不能再有效果的了
                        break;
            }
            return 1;
        }

         me->set_short_desc("正在品茶。"); 
                                message_vision(CYN "$N尋了一把空椅子，輕輕坐了下來。\n" NOR, me);
                                set_temp("has_sit", 1, me);
        return 1;
}

int valid_leave(object me, string dir)
{
                string sex = query("gender", me);
                
        if( query_temp("has_sit", me) )
        {
         me->set_short_desc(0); 
                        message_vision(CYN + ((sex=="男性")? "$N整了整衣衫，離開椅子站了起來。\n" : "$N抖了抖裙子，離開椅子站了起來。\n") + NOR, me);
                        delete_temp("has_sit", me);
        }

        return ::valid_leave(me, dir);
}


