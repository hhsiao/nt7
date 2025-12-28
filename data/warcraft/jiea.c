// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("狂[2;37;0m[2;37;0m", ({"kuangf"}));        
        set("gender", "女性");                
        set("long", "狂風[2;37;0m
它是傑一的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "jiea");
        set("owner_name", "傑一");
        set_temp("owner", "jiea");
        set_temp("owner_name", "傑一");
        ::setup();
}
