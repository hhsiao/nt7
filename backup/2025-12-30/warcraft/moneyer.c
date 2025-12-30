// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是錢袋的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "moneyer");
        set("owner_name", "錢袋");
        set_temp("owner", "moneyer");
        set_temp("owner_name", "錢袋");
        ::setup();
}
