#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("守衛書", ({ "shouwei shu", "shu" }) );
       set_weight(1000);
       set("unit", "片");
                set("long", "這是一片用竹片所制的令牌，是明教守衛弟子的身份證明。\n");
               set("value", 20);
               set("material", "bamboo");
       setup();
}
