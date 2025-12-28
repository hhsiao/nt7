// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("百科[2;37;0m[2;37;0m", ({"data"}));        
        set("gender", "女性");                
        set("long", "一隻麒麟[2;37;0m
它是歐祥的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "opus");
        set("owner_name", "歐祥");
        set_temp("owner", "opus");
        set_temp("owner_name", "歐祥");
        ::setup();
}
