//蓬萊、瀛洲、方壺、員嶠、岱輿
inherit "/inherit/room/house_base";

void create()
{
    set("short", "小岱輿");
    set("long", @LONG
此地景緻幽雅異常，放眼望去，但見柏蒼松翠，瑤草芊芊，奇花
爭妍，流水深深，雲生嶺上，風颯林間。林中有壽鹿仙狐出沒，樹上
靈禽玄鶴翩躚。遠處亭臺樓閣隱現，幽幽仙籟時聞，寂然不見人跡。
LONG);

    set("exits",
    ([
        "west" : "/d/city/sanxian-zhuang",
    ]));

    set("outdoors", "city");
    set("max_build", 2);
    set("can_build", "xian");

    setup();
    restore();
}
