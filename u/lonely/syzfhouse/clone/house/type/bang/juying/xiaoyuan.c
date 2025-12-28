// xiaoyuan.c

inherit "/inherit/room/house_door";

void create()
{
    set("short", "大門");
    set("long", @LONG
眼前一片大宅院，門頭足足高有三丈。硃紅油漆大門各是九九八十一
只大銅釘，碗口大的虎頭門扣分列門上。門旁漢白玉雕石獅張牙舞爪，氣
勢不凡。兩邊白垣烏瓦，院牆蜿蜒，不知佔地有多少畝。
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
    set("max_laodu", 6000);
    set("now_laodu", 6000);

    setup();
    restore();
}
