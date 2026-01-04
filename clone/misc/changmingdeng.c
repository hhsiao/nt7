#include <ansi.h>

inherit ITEM;

void create() {
    set_name(HIY "長明燈" NOR, ({ "changmingdeng for xueyi" }) );
    set_weight(10000);
    set("long", HIY "\n這是一盞長明燈，為雪憶而明，為雪憶引路，願其順利通往天國之路！\n NOR");
    set("value", 1);
    set("unit", "盞");
    set("no_get", 1);
}
