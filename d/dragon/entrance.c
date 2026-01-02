inherit ROOM;
#include <ansi.h>

void create() {
    set("short", "青草坪");
    set("long",
        "[1;32m松臨雨過青，花向春來美。風中有淡淡的幽香。遠遠可見山\n"
        "上祥雲瑞瑞，彩霞如練虹。地上還有一個泉眼，但看起來似乎已經乾涸了。\n"
    );
    set("exits", ([
        "north": __DIR__"spirit4"
        ]));
    set("objects", ([
        ]));
    set("no_magic", 1);
    setup();
}
