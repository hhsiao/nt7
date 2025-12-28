
inherit "/inherit/room/house_base";

void create()
{
    set("short", "孤山腳下");
    set("long", @LONG
沿路柏翠松蒼，陽光自樹梢透入，平添了不少的肅穆之氣。再向
南行，可見一座微微隆起的山丘，當地人名之曰孤山。山腳下座落著
好大的一片宅院，看上去似乎是某個幫會的駐地所在。
LONG);

    set("exits",
    ([
        "north"  : "/d/linan/gushan-jiao",
    ]));

    set("outdoors", "linan");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
