#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name(HIW "玄冰索" NOR, ({ "xuanbing suo", "xuanbing", "suo", "whip" }) );
        set_weight(4000);
        set("unit", "根");
                set("value", 1200000);
                set("material", "steel");
                set("long", HIW "\n玄冰索乃九穹七獄神兵之一。\n" NOR);
                set("wield_msg", HIR "$N輕輕抖出$n" HIR "，剎時雷聲轟鳴，一股殺氣直聶九霄。\n" );
        init_whip(110);
        setup();
}
