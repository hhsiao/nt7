#include <ansi.h>
inherit ITEM;

void create() {
    set_name(HIR "神聖血清" NOR, ({ "god blood", "god", "blood" }));
    set_weight(1000);
    set("long", HIR "這是一瓶神聖血清，似乎可以飲用。\n" NOR);
    set("unit", "瓶");
    set("value", 300000);
    setup();
}

void init() {
    add_action("do_drink", "drink");
}

int do_drink(string arg) {
    object me = this_player();

    string na, un;
    mapping my = me->query_entire_dbase();
    int time = 1800;

    na = query("name");
    un = query("unit");

    if (! arg || ! id(arg))
        return notify_fail("你要喝什麼東西？\n");

    if (me->is_busy())
        return notify_fail("急什麼，小心別噎著了。\n");

    my = me->query_entire_dbase();

    // vip的效果
    switch(me->query_viplevel() )
    {
    case 1:
        time = time - time / 10;
        break;
    case 2:
        time = time - time * 2 / 10;
        break;
    case 3:
        time = time - time * 3 / 10;
        break;
    case 4:
        time = time - time * 4 / 10;
        break;
    case 5:
        time = time - time * 5 / 10;
        break;
    case 6:
        time = time - time * 6 / 10;
        break;
    case 7:
        time = time - time * 7 / 10;
        break;
    }
    if(time < 10 ) time = 10;

    if(time() - query_temp("last_eat/blood", me) < time )
    {
        write("你剛服用過藥，需藥性發揮完效用以後才能繼續服用。\n");
        return 1;
    }

    set_temp("last_eat/blood", time(), me);


    message_vision(HIY "$N" HIY "一仰脖，將一整" + un + na +
        HIY "飲下，再也感覺不到任何疲憊。\n" NOR, me);

    my["jing"] = my["max_jing"];
    my["qi"] = my["max_qi"];
    my["eff_jing"] += my["max_jing"] / 2;
    if(my["eff_jing"] > my["max_jing"] ) my["eff_jing"] = my["max_jing"];
    my["eff_qi"] += my["max_qi"] / 2;
    if(my["eff_qi"] > my["max_qi"] ) my["eff_qi"] = my["max_qi"];
    my["neili"] = my["max_neili"];
    my["jingli"] = my["max_jingli"];

    me->start_busy(3);
    destruct(this_object());
    return 1;
}

int query_autoload() {
    return 1;
}
