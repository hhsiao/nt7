// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("我們轔[2;37;0m[2;37;0m", ({"swordalong"}));        
        set("gender", "男性");                
        set("long", "我們轔[2;37;0m
它是劍世界的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "sworda");
        set("owner_name", "劍世界");
        set_temp("owner", "sworda");
        set_temp("owner_name", "劍世界");
        ::setup();
}
