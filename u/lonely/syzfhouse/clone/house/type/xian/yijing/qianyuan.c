// xiaoyuan.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "前院");
    set("long", @LONG
這裡似乎非常安靜，倒是時不時聽見鳥兒唧唧喳喳的叫。院中不少樹
木已然有遮天之勢，肅穆非常。
LONG);

    set("exits",
    ([
        "south" : __DIR__"xiaoyuan",
        "north" : __DIR__"qianting",
    ]));

    set("owner_name", "某人");
    set("owner", "OWNER");
    set("outdoors", "OUTDOORS");

    setup();
    restore();
}
