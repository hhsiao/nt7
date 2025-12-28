// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍魔幻獸[2;37;0m[2;37;0m", ({"fffff"}));        
        set("gender", "男性");                
        set("long", "青龍魔幻獸[2;37;0m
它是不自由的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "fea");
        set("owner_name", "不自由");
        set_temp("owner", "fea");
        set_temp("owner_name", "不自由");
        ::setup();
}
