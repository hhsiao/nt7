// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("發生的額[2;37;0m[2;37;0m", ({"sdfw"}));        
        set("gender", "男性");                
        set("long", "發生的額[2;37;0m
它是水電費的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "apass");
        set("owner_name", "水電費");
        set_temp("owner", "apass");
        set_temp("owner_name", "水電費");
        ::setup();
}
