
inherit "/inherit/room/house_base";

void create()
{
    set("short", "山間松林");
    set("long", @LONG
這裡樹木參天，鳥語陣陣，倒是清靜所在。山高風自涼，林中穿
行，自覺松濤陣陣，時如古韻琴聲，時如溪水潺潺，時如曠野放歌，
時如濁浪排空，四時不同。松林深處一處莊院，好像是江湖中哪個幫
會的駐地所在。
LONG);

    set("exits",
    ([
        "east"  : "/d/qingcheng/xionger-shan",
    ]));

    set("outdoors", "qingcheng");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
