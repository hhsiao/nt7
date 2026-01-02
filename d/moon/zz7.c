// ken 1999.12.9

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create() {
    set("short", "樹林");
    set("long", @LONG
走到這裡，眼前是大片的樹叢，一片白芒芒的霧氣，擋住了去路。夜暮已
漸漸降臨，四下裡靜無人聲，只聽到貓頭鷹在不遠的枯樹上詭異地咕咕作響，
你不禁開始感到有些毛骨聳然。
LONG
    );
    set("exits", ([
        "south": __DIR__"zz1"
        ]));

    set("item_desc", ([
        "霧氣": "一片白芒芒的霧氣，瀰漫在這片樹林之中，如果能站得高些，或許...\n",
        "枯樹": "一棵早已乾枯了的樹，樹幹上已開始腐朽。\n"
        ]) );
    set("coor/x",-10);
    set("coor/y", 1010);
    set("coor/z", 0);
    setup();
}

void init() {
    add_action("do_climb", "climb");
}

int climbbusy(object me)
{  object room;
    room = find_object("/u/moon/treetop");
    if(!objectp(room)) room = load_object("/u/moon/treetop");
    me->move(room);
    message_vision("\n$N小心翼翼地沿著快要朽斷的樹幹慢慢地爬了上來。\n", me);
    return 1;
}

int do_climb(string arg) {
    object me;
    if(!arg || arg=="")
    {
        write("你要爬什麼？\n");
        return 1;
    }
    if(arg == "kushu" || arg == "枯樹" )
    {
        me = this_player();
        message_vision("\n\n$N抬頭看了看枯樹的頂端，手腳並用，向上爬去......\n\n", me);
        me->start_busy(1);
        call_out("climbbusy", 1, me);
        me->stop_busy();
        return 1;
    }
    else
        write("你要爬什麼？\n");
    return 1;
}
