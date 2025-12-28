// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("華山青龍[2;37;0m[2;37;0m", ({"hsdragon"}));        
        set("gender", "男性");                
        set("long", "華山青龍[2;37;0m
它是張華山的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "huashanxz");
        set("owner_name", "張華山");
        set_temp("owner", "huashanxz");
        set_temp("owner_name", "張華山");
        ::setup();
}
