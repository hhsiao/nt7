// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m走火入魔[2;37;0m[2;37;0m", ({"horse"}));        
        set("gender", "男性");                
        set("long", "$RED$走火入魔[2;37;0m
它是毒蟲蟲的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "bnkk");
        set("owner_name", "毒蟲蟲");
        set_temp("owner", "bnkk");
        set_temp("owner_name", "毒蟲蟲");
        ::setup();
}
