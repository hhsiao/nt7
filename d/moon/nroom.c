// ken 1999.12.9

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create() {
    set("short", "內室");
    set("long", @LONG
這裡只有柔和的燈光，華麗的陳設，精美的傢俱，一切佈置的是
那麼的恰如其分，旁邊縷金香爐裡散發出的陣陣幽香，另你忘卻了
一切煩惱和疲勞。
LONG	);
    set("objects", ([
        __DIR__"obj/xianglu" : 1
        ]) );
    set("coor/x",-50);
    set("coor/y", 1110);
    set("coor/z", 40);
    setup();
}

void init() {
    add_action("do_turn", "turn");
}

void close_path() {
    if(!query("exits/north") ) return;
    message("vision", "\n香爐又轉了回來，暗門無聲無息地合上了。\n", this_object() );
    delete("exits/north");
}

void closed_path() {
    if(!query("exits/east") ) return;
    message("vision", "\n香爐又轉了回來，暗門無聲無息地合上了。\n", this_object() );
    delete("exits/east");
}


int do_turn(string arg)
{    object me;
    me = this_player();
    if(!arg || arg=="")
    {
        write("你想向那個方向轉動？\n");
        return 1;
    }
    if(arg == "left")
    { if((int)me->query("force_factor") >= 50 )
            {   message_vision("香爐吱吱轉動，北牆上無聲無息地裂開一扇暗門。\n", me);
            if(!query("exits/north") )
            {
                set("exits/north", __DIR__"mroom");
                call_out("close_path", 5);
            }
            return 1;
        }
        else
            write("香爐紋絲不動。\n");
        return 1;
    }
    else
        if(arg == "right")
    { if((int)me->query("force_factor") >= 50 )
            {  message_vision("香爐吱吱轉動，東牆上無聲無息地裂開一扇暗門。\n", me);
            if(!query("exits/east") )
            {
                set("exits/east", __DIR__"wroom1");
                call_out("closed_path", 5);
            }
            return 1;
        }
        else
            write("香爐紋絲不動。\n");
        return 1;
    }
}
