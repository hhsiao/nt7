// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "清[2;37;0m
它是醋聞聞的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "cuwenwen");
        set("owner_name", "醋聞聞");
        set_temp("owner", "cuwenwen");
        set_temp("owner_name", "醋聞聞");
        ::setup();
}
