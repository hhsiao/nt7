// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m龍[1;37m暝[2;37;0m[2;37;0m", ({"att"}));        
        set("gender", "男性");                
        set("long", "幽駒戾天[2;37;0m
它是龍幽的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "frong");
        set("owner_name", "龍幽");
        set_temp("owner", "frong");
        set_temp("owner_name", "龍幽");
        ::setup();
}
