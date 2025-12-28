
inherit "/inherit/room/house_base";

void create()
{
    set("short", "山谷");
    set("long", @LONG
這是埡口內側的狹小山谷，兩邊巖壁怪石嶙峋，鮮有植被。遠處
崑崙山脈綿延千里，群山起伏，峰頂白雪皚皚終年不化。東面山坡上
依山而建一座大院，看來好像是江湖中哪個幫會的駐地所在。
LONG);

    set("exits",
    ([
        "east"  : "/d/kunlun/kunlun-shankou",
    ]));

    set("outdoors", "kunlun");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
