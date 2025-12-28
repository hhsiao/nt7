// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白馬[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "白馬[2;37;0m
它是冒險遊戲的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "avg");
        set("owner_name", "冒險遊戲");
        set_temp("owner", "avg");
        set_temp("owner_name", "冒險遊戲");
        ::setup();
}
