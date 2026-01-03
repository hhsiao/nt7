inherit ITEM;
inherit "/d/war/diablo";
#include <ansi.h>

void create() {

    set_name("墓碑", ({"tomb"}));
    if(clonep() )
        set_default_object(__FILE__);
    else {

        set("long", "墳墓。(相關指令touch)\n");
        set("unit", "個");
        set("base_weight", 50);
        set("tomb", 1);
        set("no_get", 1);
        set("zone", "roger");


        set("act", "act1");

    }
    set_coor();

}

void init() {
    add_action("do_touch", "touch");
}

int do_touch(string arg) {
    object me, obj;
    mapping coor;
    me = this_player();

    //trans=query("trans_"+query("act"),me);
    //if(mapp(trans)) ks=keys(trans);
    if(!arg||!objectp(obj = present(arg, environment(me))) )
        return 0;

    if(obj!=this_object() )  return 0;
    if(!query("block_move", me) )
    {
        tell_object(me, "你還沒死，復活啥。\n");
        return 1;
    }

    if(me->query_busy() )
    {
        tell_object(me, "你正忙著呢，再等一會。\n");
        return 1;
    }

    if(me->distance(obj)>40 )
    {
        tell_object(me, "請再靠近一點，40米以內。\n");
        return 1;
    }

    coor = ([ "coor_x": query("coor/x"),
        "coor_y": query("coor/y"),
        "coor_z": query("coor/z")
        ]);


    tell_object(me, HIG"你拍了下墓碑，從墳頭站了起來。\n"NOR);
    delete("block_move", me);
    me->start_busy(5);
    return 1;
}
