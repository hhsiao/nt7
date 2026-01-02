// ken 1999.12.9

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create() {
    set("short", "幽香湖");
    set("long", @LONG
這是一個碧清的小湖，湖邊盛開著各式各樣的奇花異草。
一陣幽風襲面而來，頓覺四周清香暗湧。北面是陡峭的山崖，
剛才所見的燈光似乎就來自這座山上。
LONG
    );
    set("exits", ([
        "west": __DIR__"caodi"
        ]));
    set("coor/x",-20);
    set("coor/y", 1050);
    set("coor/z", 0);
    setup();
}
void init() {
    add_action("do_fillwater", "fillwater");
}
int do_fillwater(string arg) {
    object *list, ob;
    int i, can_fillwater;

    if(!arg || arg=="" ) return 0;

    if(arg=="skin" || arg=="wineskin" ) {
        list = all_inventory(this_player());
        i = sizeof(list);
        can_fillwater = 0;
        while (i--) {
            if (((string)list[i]->query("liquid/type") == "alcohol")
                || ((string)list[i]->query("liquid/type") == "water") ) {
                    ob = list[i];
                    can_fillwater = 1;
                ob->set("liquid", ([
                    "type": "water",
                    "name": "幽香湖水",
                    "remaining": 15,
                    "drunk_apply": 6
                    ]) );
                write("你從幽香湖裡裝滿了水！ \n");
                return 1;
            }
        }
        if (can_fillwater ==0) {
            write("你沒有裝水的東西啊....\n");
            return 1;
        }
    }
    else {
        write("你要往什麼東西里灌水？\n");
    }
    return 1;
}
