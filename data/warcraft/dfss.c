// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m小黃[2;37;0m[2;37;0m", ({"yellow"}));        
        set("gender", "女性");                
        set("long", "小黃龍[2;37;0m
它是東方叔叔的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "dfss");
        set("owner_name", "東方叔叔");
        set_temp("owner", "dfss");
        set_temp("owner_name", "東方叔叔");
        ::setup();
}
