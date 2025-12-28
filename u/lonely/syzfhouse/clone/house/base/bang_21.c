
inherit "/inherit/room/house_base";

void create()
{
    set("short", "海岸");
    set("long", @LONG
這裡是海港外十許裡的海灘，倒也靜謐。極目遠望，但見點點白
帆若隱若現。細碎的浪花拍打著沙地，嘩嘩作響。灘外一箭之地，有
一處大院落，似乎是江湖中哪個幫會的駐地所在。
LONG);

    set("exits",
    ([
        "north"  : "/clone/room/matou/dg",
    ]));

    set("outdoors", "beijing");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
