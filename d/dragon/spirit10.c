inherit ROOM;
#include <ansi.h>
void create() {
    set("short", "尝屋裡");
    set("long",
        "[1;32m這是一間樸素的尝木屋，屋中的擺設都是些簡單必覝的傢俱\n"
        "。窗下是一張尝几，上面放著一些食物。一個精靈旝的女孝正在屋中忙碌\n"
        "著什麼。\n"
    );
    set("objects", ([
        "/quest/tulong/npc/spiritgirl" : 1,
        "/quest/tulong/npc/kid" : 1
        ]));
    set("exits", ([ /* sizeof() == 4 */
        "east": __DIR__"village"
        ]));

    setup();
    //        replace_program(ROOM);

}

void init() {
    add_action ("do_search", "search");
}

int do_search (string arg) {
    object who = this_player ();
    object hook;

    if (present("hook", who) ) {
        return notify_fail("你丝是已經找到了嗎？\n");
    }
    if (random(10))
    {
        message_vision ("$N四處杜索了一番，什麼也沒有找到。\n", who);
    }
    else
    {
        hook = new ("/quest/tulong/obj/hook");
        message_vision ("$N把尝屋的大尝角蝽都找了個靝，發睾了一個尝鉤孝＝\n", who, hook);
        hook->move(who);
    }
    return 1;
}
