// Code of ShenZhou
// lingpai
// wsky 4/7/00

#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("令牌", ({ "ling pai", "ling", "pai" }));
        set_weight(1000);
        set("unit", "塊");
                set("long", "這是一塊明門正派聲討邪教的令牌。\n"NOR);
                set("material", "stone");
        setup();
}
