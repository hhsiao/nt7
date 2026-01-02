// ken 1999.12.9

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create() {
    set("short", "山莊前院");
    set("long", @LONG
走到這裡，你的視野豁然開朗，剛才的壓抑一掃而光。此處建築黃金
為頂，白玉為階，遠見層層疊疊的琉璃瓦在夕陽的餘輝下熠熠生光，
近處幾隻仙鶴在松柏掩映的草地上悠閒地漫步，望之有如神仙境界。
LONG	);
    set("exits", ([
        "north": __DIR__"gaden",
        "westdown": __DIR__"cookroom",
        "eastdown": __DIR__"lianroom",
        "southeast": __DIR__ "bi"
        ]));
    set("objects", ([
        __DIR__"npc/guards" : 2
        ]) );
    set("coor/x",-30);
    set("coor/y", 1090);
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
        room = find_object("/n/moon/bi");
        if(!objectp(room)) room = load_object("/u/moon/bi");
        message_vision("\n$N信步瀏覽，轉眼走過了假山。\n\n", me);
        me->move(room);
        return 1;
    }
    else
        write("你要轉過什麼？\n");
    return 1;
}
