// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("及時雨[2;37;0m[2;37;0m", ({"lsjsy"}));        
        set("gender", "男性");                
        set("long", "及時雨[2;37;0m
它是打包三號的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "bagc");
        set("owner_name", "打包三號");
        set_temp("owner", "bagc");
        set_temp("owner_name", "打包三號");
        ::setup();
}
