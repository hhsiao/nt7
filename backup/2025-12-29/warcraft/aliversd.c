// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m魚香肉絲[2;37;0m[2;37;0m", ({"pesib"}));        
        set("gender", "男性");                
        set("long", "魚香肉絲[2;37;0m
它是阿爾死的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "aliversd");
        set("owner_name", "阿爾死");
        set_temp("owner", "aliversd");
        set_temp("owner_name", "阿爾死");
        ::setup();
}
