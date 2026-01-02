// ken 1999.12.9

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create() {
    set("short", "密室");
    set("long", @LONG
一間小小的密室，一塵不染，看來經常有人來打掃，
可是現在這裡除了一個書櫃以外，別的什麼都沒有。
LONG	);
    set("objects", ([
        __DIR__"obj/bookcase" : 1,
        __DIR__"npc/xiao" : 1
        ]) );
    set("exits/south", __DIR__"nroom");
    set("coor/x",-50);
    set("coor/y", 1120);
    set("coor/z", 40);
    setup();
}

void reset() {
    object *inv;
    object item1, bookcase;
    ::reset();

    bookcase = present("bookcase", this_object());
    inv = all_inventory(bookcase);
    if(!sizeof(inv)) {
        item1 = new(__DIR__"obj/book");
        item1->move(bookcase);
    }
}
