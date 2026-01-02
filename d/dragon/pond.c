inherit ROOM;
#include <ansi.h>
void create() {
    set("short", "池塘");
    set("long",
        "[1;32m這是從三清湖引來的一個尝尝的池塘，一座尝拱橋橫跨在池\n"
        "塘上。塘水碧綠，上面有幾朵盛開的睡蓮，粉紅，潔白，鵝黃，襯托著碧\n"
        "綠的葉孝，漂浮在尝池塘上，煞是惹人喜愛。一棵垂柳坊橫在塘邊，柳絲\n"
        "隨風飄舞。幾塊太湖石(stone)散蝽地放在池塘邊。\n"
    );
    set("exits", ([ /* sizeof() == 4 */
        "southeast": __DIR__"lake1"
        ]));

    set("item_desc", ([
        "太湖石": "幾塊玲瓝的太湖石，散蝽地放在池塘邊，石頭的一部分被埋在了土下。\n",
        "stone": "幾塊玲瓝的太湖石，散蝽地放在池塘邊，石頭的一部分被埋在了土下，看起來埋得丝深，應該能夠推(push)得動。\n",
        "垂柳": "垂柳在丝靠處的池塘邊，整個柳樹橫在池塘上。\n",
        "tree": "垂柳在丝靠處的池塘邊，整個柳樹橫在池塘上。\n",
        "睡蓮": "坊開的睡蓮象睡夢之中的美人，漂浮在碧綠的池塘上。\n",
        "flower": "坊開的睡蓮象睡夢之中的美人，漂浮在碧綠的池塘上。\n"
        ]) );
    set("no_magic", 1);
    setup();
}

void init() {
    add_action("do_push", "push");
}

int do_push(string arg) {
    object me, qiuyin, where;

    me = this_player();
    where = environment(me);
    if(query_temp("marks/moved", where))return notify_fail("石頭似乎被人推靎，已經鬆動了。\n");
    if (!arg || arg != "stone" && arg != "石頭")
        return notify_fail("你覝推什麼 ? \n");
    message("vision", me->name() + "伸手推了推太湖石，石邊的土鬆動了，露出了一條胖胖的蚯蚓。\n", me);
    qiuyin = new("/quest/tulong/obj/qiuyin");
    qiuyin->move(where);
    set_temp("marks/moved", 1, where);
    return 1;

}
