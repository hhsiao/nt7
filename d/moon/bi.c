// ken 1999.12.9

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create() {
    set("short", "假山");
    set("long", @LONG
 剛進莊門，一座高大的假山就擋住了你的視線。雖看不見莊內的情形，
但耳中卻聽得不遠處隱隱傳來人聲。
LONG	);
    set("exits", ([
        "south": __DIR__"door"
        ]));
    set("objects", ([
        __DIR__"obj/jiashan" : 1
        ]) );
    set("coor/x",-30);
    set("coor/y", 1080);
    set("coor/z", 40);
    setup();
}
void init() {
    add_action("do_around", "around");
}

int do_around(string arg) {
    object room;
    object me;
    if(!arg || arg=="")
    {
        write("你要轉過什麼？\n");
        return 1;
    }
    if(arg == "jiashan" || arg == "假山" )
    {
        me = this_player();
        room = find_object("/n/moon/fgaden");
        if(!objectp(room)) room = load_object("/u/moon/fgaden");

        message_vision("\n$N在假山中東一轉，西一轉，眼前突然現出一片輝煌。\n\n", me);
        me->move(room);
        return 1;
    }
    else
        write("你要轉過什麼？\n");
    return 1;
}
