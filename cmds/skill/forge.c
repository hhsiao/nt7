// forging.c

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg) {
    object item;

    if(!arg )
        return notify_fail("你要鍛造什麼物品？\n");

    if(me->is_busy() )
        return notify_fail("先忙完了你的事情再做這件事情吧！\n");

    if(me->is_fighting() )
        return notify_fail("你現在正在打架，沒時間做這些事情。\n");

    if(!objectp(item = present(arg, me)) )
        return notify_fail("你身上沒有這樣道具。\n");

    if(!item->is_item_make() )
        return notify_fail("你只能鍛造自造的防具！\n");

    if(!stringp(item->item_owner()) ||
        item->item_owner() != query("id", me) )
        return notify_fail("你只能鍛造自己的防具！\n");

    if(item->is_weapon() || item->is_unarmed_weapon() )
        return notify_fail("你只能鍛造自己的防具！\n");

    if(query("equipped", item) )
        return notify_fail("你先解除" + item->name() + "的裝備再說！\n");

    notify_fail(item->name() + "沒有辦法被鍛造。\n");

    return item->do_forge(me);
}


int help(object me) {
    write(@HELP
指令格式 : forge <防具>

這個指令可以讓你鍛造防具，提升防具到準10LV，每次消耗一定的最大內力。

HELP
    );
    return 1;
}
