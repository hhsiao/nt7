#include <ansi.h>

inherit ITEM;

void create() {
    set_name(HIR "龍晶" NOR, ({ "dragon soul" }) );
    set_weight(1);
    set("long", "這是龍的內丹，雞蛋大小，如火焰般赤紅。用法：reset\n");
    set("unit", "顆");
    set("value", 50000);
    set("no_drop", 1);
    set("auto_load", 1);
    setup();
}

void init() {
    if(this_player() == environment() )
        add_action("do_reset", "reset");
}

int do_reset(string arg) {
    object ob = this_player();
    int times, n;

    if(!query("ability1", ob) && !query("ability2", ob) )
    {
        addn("max_neili", -50, ob);
        message_vision(HIR "$N試圖吸納龍晶，但身體承受不了，結果適得其反，受到內力反噬！\n" NOR, ob);
        destruct(this_object());
        return 1;
    }

    addn("use_dragon_soul", 1, ob);
    n = query("use_dragon_soul", ob);
    times = query("reset_ability", ob);

    if(times > 24 ) times = 24;
    if(n > times )
    {
        delete("use_dragon_soul", ob);
        addn("reset_ability", 1, ob);

        message_vision(HIY "$N運勁吸納龍晶，只見$N面色赤紅如火，體內真氣源源而生，能力點（ability）重置。\n" NOR, ob);

        delete("ability1", ob);
        delete("ability2", ob);
        delete("ability_count", ob);
        delete("learned_ability", ob);

        ob->save();

        destruct(this_object());
        return 1;
    }
    message_vision(HIY "$N運勁吸納龍晶，只見$N面色赤紅如火，體內真氣源源而生，但似乎吸納龍晶的能量不足以讓能力點（ability）重置。\n" NOR, ob);
    destruct(this_object());
    return 1;
}
