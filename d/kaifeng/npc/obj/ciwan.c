#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW "白天目磁碗" NOR, ({ "baitianmu ciwan", "ciwan", "bai" }) );
        set_weight(5000);
        set("unit", "只");
                set("long", HIW "純白無瑕,薄如紙的上佳瓷器。\n" NOR);
                set("value", 1500);
}
