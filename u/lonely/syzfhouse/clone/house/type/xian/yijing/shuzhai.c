// dongxiang.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "書齋");
    set("long", @LONG
這裡是主人平素讀書寫字的地方，乾淨明亮。文房四寶整整齊齊的擺
在桌子上面。
LONG);

    set("exits",
    ([
        "west"  : __DIR__"houting",
    ]));

    set("no_learn", 1);
    set("owner", "OWNER");
    set("owner_name", "某人");

    setup();
    restore();
}
