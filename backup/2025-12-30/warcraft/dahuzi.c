// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("妖姬[2;37;0m[2;37;0m", ({"toto"}));        
        set("gender", "女性");                
        set("long", "絕世妖姬[2;37;0m
它是不習慣的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "dahuzi");
        set("owner_name", "不習慣");
        set_temp("owner", "dahuzi");
        set_temp("owner_name", "不習慣");
        ::setup();
}
