
inherit "/inherit/room/house_base";

void create()
{
    set("short", "得勝山側");
    set("long", @LONG
這裡是揚州的東城門郊外，再向東便通向得勝山了。從這裡看去
山上山下樹木長得特別茂盛，平時行人稀少。北面座落著好大的一片
宅院，看上去似乎是某個幫會的駐地所在。
LONG);

    set("exits",
    ([
        "southeast" : "/d/city/jiaowai",
    ]));

    set("outdoors", "city");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
