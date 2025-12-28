//wkantai2.c  by Lonely

#include <room.h>

inherit ROOM;

void create()
{        
        set("short", "西較武場看臺");
        set("long",
"這是唐門的西較武場看臺。看臺上除了幾排座位外，中間設了三張金\n"
"鑄銀雕的太師椅。觀看比武大賽的最佳位置，就在這個看臺上。當然，唐\n"
"門主持大賽的掌權者們的座位，也就設在這裡。你站在看臺上，鬥志激昂。\n"
"這裡的西面，是西較武場，南北各有一個看臺。東面是東較武場的入口。\n"
);        
        set("no_steal", "1");
        set("no_fight", "1");
        set("exits", ([
                "east" : __DIR__"wrukou",
                "north" : __DIR__"wkantai1",
                "south" : __DIR__"wkantai3",
        ]));
        setup();
        replace_program(ROOM);
}