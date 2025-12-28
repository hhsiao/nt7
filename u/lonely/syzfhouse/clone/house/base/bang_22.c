
inherit "/inherit/room/house_base";

void create()
{
    set("short", "嘉峪關東");
    set("long", @LONG
這是嘉峪關東首的黃土山丘。低矮的灌木四處散佈，倒也長得有
些蔥蘢。站在此處西望，嘉峪關關城樓閣高聳，巍峨壯觀。再往東去
幾步是一座恢宏的莊院，看似江湖中哪個幫會的駐地所在。
LONG);

    set("exits",
    ([
        "west"  : "/d/xiyu/jiayu-guan",
    ]));

    set("outdoors", "xiyu");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
