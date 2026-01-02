#include <ansi.h>
inherit ITEM;

void create() {
    set_name(HIC "玲瓏飛天佩" NOR, ({ "feitian pei", "feitian", "pei" }) );
    set_weight(5000);
    set("unit", "只");
    set("long", HIC "經唐三彩燒製的玲瓏飛天佩，非常的昂貴。\n" NOR);
    set("value", 1500);
}
