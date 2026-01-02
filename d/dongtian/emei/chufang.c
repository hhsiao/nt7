// This program is a part of NITAN MudLIB
// redl 2013/9
#include <ansi.h>
#include <room.h>
inherit __DIR__"normal.c";

void create() {
    set("short", "廚房");
    set("long",
        "這是廚房，幾個看起來就是凡人的小廝和健婦正在辛勤忙碌著。一陣飯\n"
        "菜的清香飄過，使人食慾大振。\n"
    );
    //set("outdoors", "dongtian");
    set("exits", ([ /* sizeof() == 1 */
        "south": __DIR__"caidi"
        ]));

    set("objects", ([
        "/clone/fam/pill/water.c" : random(4) + 3,
        "/clone/fam/pill/food.c" : random(21) + 10,
        "/clone/fam/pill/food1.c" : random(3)
        ]));

    set("no_steal", 1);
    set("no_beg", 1);
    set("no_rideto", 1);
    set("no_flyto", 1);
    set("no_drift", 1);
    set("no_sleep_room", 1);
    set("max_carry_user" , 20);

    setup();
}
