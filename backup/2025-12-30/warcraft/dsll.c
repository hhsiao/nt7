// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("及時雨[2;37;0m[2;37;0m", ({"lsjsy"}));        
        set("gender", "男性");                
        set("long", "及時雨[2;37;0m
它是鋤禾的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "dsll");
        set("owner_name", "鋤禾");
        set_temp("owner", "dsll");
        set_temp("owner_name", "鋤禾");
        ::setup();
}
