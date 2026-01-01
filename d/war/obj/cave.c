#include <ansi.h>
inherit ITEM;
inherit "/d/war/diablo";

#define L_SIZE 600
#define S_SIZE 100
void create() {

    set_name("廢棄的洞穴", ({"cave"}));
    set("long", "廢棄的洞穴。(相關指令touch)\n");
    set("unit", "個");
    set("base_weight", 50);

    set("no_get", 1);
    set("zone", "roger");
    set("enter_num", 1);
    set("level", 200);
    set("act", "act1");
    set("cave", 1);
    set_coor();

}

void init() {
    add_action("do_touch", "touch");
}

int do_touch(string arg) {
    object me, obj, exit;
    int n;
    mapping coor,*walls;

    me = this_player();
    n = 100000 + random(100000);

    if(!arg||!objectp(obj = present(arg, environment(me))) )
        return 0;

    if(obj!=this_object() )
        return 0;

    if(query("owner_id", obj)&&query("owner_id", obj)!=me)
    {
        tell_object(me, "這是別人的任務洞穴，你無法進入。\n");
        return 1;
    }

    if(me->query_busy() )
    {
        tell_object(me, "你正忙著呢，再等一會。\n");
        return 1;
    }

    if(!wizardp(me)&&me->distance(obj)>40 )
    {
        tell_object(me, "請再靠近一點，40米以內。\n");
        return 1;
    }

    if(!query("have_wall") )
    {
        set("have_wall", 1);

        coor=
        ([
            "no_door": 1, "no_tomb": 1, "act": "act1", "name": "邪惡洞穴", "bandit": RED"洞穴怪"+random(100) + "型"NOR, "level": query("level"), "item": "boots",
            "x1": query("coor/x"), "x2": query("coor/x") + L_SIZE, "y1": query("coor/y"), "y2": query("coor/y") - L_SIZE, "z1": query("coor/z") + n, "z2": query("coor/z") + n
            ]);

        walls = environment()->generate_wall(query("coor/x"), query("coor/y"), query("coor/z"), coor);
        environment()->add_zone_range(([replace_string(sprintf("%O.c", obj), "\"", ""):coor]));
        environment()->generate_bandit(replace_string(sprintf("%O.c", obj), "\"", ""), coor);

        exit = new("/d/war/obj/out");
        set("zone", replace_string(sprintf("%O.c", obj), "\"", ""), exit);
        set("coor/x", query("coor/x") - 80 - S_SIZE + L_SIZE, exit);
        set("coor/y", query("coor/y") + 80 + S_SIZE - L_SIZE, exit);
        set("coor/z", query("coor/z") + n, exit);
        set("out_coor", query("coor"), exit);

        exit->move(environment());
        set("walls", walls, exit);
    }

    tell_object(me, HIG"你一頭鑽進了"+query("name") + "。\n"NOR);
    set("coor/x", query("coor/x") + 20 + S_SIZE, me);
    set("coor/y", query("coor/y") - 20 - S_SIZE, me);
    set("coor/z", query("coor/z") + n, me);

    if(query("enter_num") ) addn("enter_num",-1);
    if(!query("enter_num") )
    {
        message_vision("洞穴入口已崩塌", me);
        destruct(this_object());
    }
    return 1;
}
