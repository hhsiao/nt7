#include <ansi.h>
inherit ITEM;

void create()
{
        set_weight(50);
        set_name(HIG "翔" NOR, ({"xiang"}));
        set("unit", "坨");
                set("long", "這是一坨翔，隱隱透露著一股清香，讓人忍不住有一種吃一口的衝動！\n");
                set("value", 50);
                set("poison_type", "poison");
                set("can_pour", 1);
                set("can_daub", 1);
                set("can_drug", 1);
                set("poison", ([
                        "level" : 1100,
                        "id"    : "xiang",
                        "name"  : "翔",
                        "duration": 40,
                ]));
                set("no_sell", 1);
                set("only_do_effect", 1);
        setup();
}

int do_effect(object me)
{
        message_vision("$N大口一張，狂吃了一坨翔。\n",
                       me);
        set_temp("die_reason", "吃了翔暴斃身亡了", me);
        me->die();
        destruct(this_object());
        return 1;
}
