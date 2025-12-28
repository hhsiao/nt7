// xiaoyuan.c

inherit "/inherit/room/house_door";

void create()
{
    set("short", "大門");
    set("long", @LONG
眼前一片宅院，門頭高約兩丈，硃紅油漆大門各是八八六十四隻大銅
釘，碗口大的虎頭門扣分列門上。門旁石獅張牙舞爪，氣勢迫人。兩邊白
垣烏瓦，院牆蜿蜒，不知佔地有多少畝。
LONG);

    set("exits",
    ([
        "out"    : __FILE__,
    ]));

    set("owner_name", "某人");
    set("owner", "OWNER");
    set("huyuan", __DIR__"huyuan");
    set("outdoors", "OUTDOORS");
    set("set_exits", "north");
    set("set_entry", "wuchang");
    set("max_laodu", 3000);
    set("now_laodu", 3000);

    setup();
    restore();
}
