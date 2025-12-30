// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("布萊恩[2;37;0m[2;37;0m", ({"bryan"}));        
        set("gender", "男性");                
        set("long", "可愛聰明的布萊恩！[2;37;0m
它是張楚靈的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "maliyu");
        set("owner_name", "張楚靈");
        set_temp("owner", "maliyu");
        set_temp("owner_name", "張楚靈");
        ::setup();
}
