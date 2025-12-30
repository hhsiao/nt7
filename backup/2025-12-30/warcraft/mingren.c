// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m文太[2;37;0m[2;37;0m", ({"toad"}));        
        set("gender", "男性");                
        set("long", "這就是火影忍者中的蛤蟆老大。[2;37;0m
它是歐陽鳴人的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "mingren");
        set("owner_name", "歐陽鳴人");
        set_temp("owner", "mingren");
        set_temp("owner_name", "歐陽鳴人");
        ::setup();
}
