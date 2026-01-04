#include <ansi.h>
#define BATTLEFIELD3_D     "/adm/daemons/battlefieldd3.c"
inherit COMBINED_ITEM;

void create() {
    set_name(HIC"仇"NOR CYN"殺"HIC"勳"NOR CYN"章"NOR, ({ "chousha insigne" }) );
    set_temp("status", HIG"傳"NOR GRN"奇");

    set("long", "從門派戰爭中獲得的仇殺勳章，可以用來兌換稀有的物品，也可以\n"
        "使用(use)它重新進入戰場。\n");
    set("unit", "堆");
    set("base_unit", "枚");
    set("base_value", 100);
    set("no_sell", 1);
    set("no_drop", 1);
    set("no_give", 1);
    setup();
    set_amount(1);
}

void init() {
    add_action("do_use", "use");
}

int do_use(string arg) {
    object me;

    me = this_player();

    if(!BATTLEFIELD3_D->is_battle_start() )
        return notify_fail("戰鬥還沒有開始報名。\n");

    if(!BATTLEFIELD3_D->is_battle_start() )
        return notify_fail("戰鬥還沒有開始。\n");

    if(!BATTLEFIELD3_D->in_battle(me) )
        return notify_fail("你可以使用battle join來參加戰鬥。\n");

    if(BATTLEFIELD3_D->inside_battlefield(me) )
        return notify_fail("你已經在戰場中了，為榮譽而戰吧。\n");

    BATTLEFIELD3_D->init_player(me);
    add_amount(-1);
    return 1;
}
