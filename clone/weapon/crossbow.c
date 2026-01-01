// crossbow.c

#include <ansi.h>

inherit __DIR__"bow";

void create()
{
        set_name("弩", ({ "cross bow", "bow", "nu" }));
        set_weight(2000);
        set("unit", "張");
                set("long", "一張弩，打造得極為精緻，具有極好的準確度。\n");
                set("value", 250000);
                set("power", 250000);   // 攻擊威力
                set("accuracy", 180);   // 準確度150%
        setup();
}
