// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白馬[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "白馬[2;37;0m
它是動作遊戲的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "act");
        set("owner_name", "動作遊戲");
        set_temp("owner", "act");
        set_temp("owner_name", "動作遊戲");
        ::setup();
}
