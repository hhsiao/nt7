// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[36m青玉龍[2;37;0m[2;37;0m", ({"gdragon"}));        
        set("gender", "男性");                
        set("long", "這是一條通體發出寶玉光芒的神龍。[2;37;0m
它是花千樹的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "light");
        set("owner_name", "花千樹");
        set_temp("owner", "light");
        set_temp("owner_name", "花千樹");
        ::setup();
}
