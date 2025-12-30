// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("狂[2;37;0m[2;37;0m", ({"kuangf"}));        
        set("gender", "女性");                
        set("long", "狂風[2;37;0m
它是傑二的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "jieb");
        set("owner_name", "傑二");
        set_temp("owner", "jieb");
        set_temp("owner_name", "傑二");
        ::setup();
}
