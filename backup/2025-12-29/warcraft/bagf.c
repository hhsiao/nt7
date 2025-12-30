// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("及時雨[2;37;0m[2;37;0m", ({"lsjsy"}));        
        set("gender", "男性");                
        set("long", "及時雨[2;37;0m
它是打包六號的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "bagf");
        set("owner_name", "打包六號");
        set_temp("owner", "bagf");
        set_temp("owner_name", "打包六號");
        ::setup();
}
