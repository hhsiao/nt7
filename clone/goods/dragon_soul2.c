#include <ansi.h>

inherit ITEM;

void create() {
    set_name(HIR "龍元" NOR, ({ "dragon soul2" }) );
    set_weight(1);
    set("long", "這是修煉成元神後的高等龍的內丹，拳頭大小，如火焰般赤紅。用法：reset\n");
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

int do_reset() {
    object ob = this_player();
    int times, n;

    if(!query("talent", ob) && !query("talent_count", ob) )
    {
        addn("max_neili", -50, ob);
        message_vision(HIR "$N試圖吸納龍元，但身體承受不了，結果適得其反，受到內力反噬！\n" NOR, ob);
        destruct(this_object());
        return 1;
    }

    addn("use_dragon_soul2", 1, ob);
    n = query("use_dragon_soul2", ob);
    times = query("reset_talent", ob);

    if(times > 24 ) times = 24;
    if(n > times )
    {
        delete("use_dragon_soul2", ob);
        addn("reset_talent", 1, ob);

        message_vision(HIY "$N運勁吸納龍元，只見$N面色赤紅如火，體內真氣源源而生，天賦點（talent）重置。\n" NOR, ob);

        delete("talent", ob);
        delete("talent_count", ob);
        delete("learned_energy", ob);

        ob->save();

        destruct(this_object());
        return 1;
    }
    message_vision(HIY "$N運勁吸納龍元，只見$N面色赤紅如火，體內真氣源源而生，但似乎吸納龍元的能量不足以讓天賦點（talent）重置。\n" NOR, ob);
    destruct(this_object());
    return 1;
}
