// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m的哥[2;37;0m[2;37;0m", ({"nannan"}));        
        set("gender", "男性");                
        set("long", "的哥[2;37;0m
它是華大哥的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "huashana");
        set("owner_name", "華大哥");
        set_temp("owner", "huashana");
        set_temp("owner_name", "華大哥");
        ::setup();
}
