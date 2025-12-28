// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("烏龜[2;37;0m[2;37;0m", ({"jackya"}));        
        set("gender", "男性");                
        set("long", "這是隻烏龜[2;37;0m
它是一樣的是的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "jackyb");
        set("owner_name", "一樣的是");
        set_temp("owner", "jackyb");
        set_temp("owner_name", "一樣的是");
        ::setup();
}
