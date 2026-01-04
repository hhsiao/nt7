
#include <ansi.h>

inherit ITEM;

void create() {
    set_name(HIY "高級清師令" NOR, ({ "qingshi ling2", "qingshi", "ling2" }) );
    set_weight(100);

    set("long", HIG "可使用他用來無損脫離師門一次，必須脫離前使用(use ling2)才有效。\n" NOR);
    set("value", 1);
    set("no_sell", 1);
    set("unit", "塊");
    set("auto_load", 1);

    setup();
}

void init() {
    add_action("do_qingshi", "use");
}

int do_qingshi(string arg) {
    object me;
    me = this_player();

    if(!arg ) return notify_fail("使用格式：use ling2\n");

    addn("skill_expell_penalty_tsl", 1, me);

    write(HIM "高級清師令使用成功，你增加了一次可以無損脫師的機會！\n" NOR);
    write(HIG "高級清師令化作一縷青煙逐漸消失了！\n" NOR);
    me->save();
    destruct(this_object());

    return 1;
}
