// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("船[2;37;0m[2;37;0m", ({"chuan"}));        
        set("gender", "男性");                
        set("long", "船[2;37;0m
它是蒼白的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "sor");
        set("owner_name", "蒼白");
        set_temp("owner", "sor");
        set_temp("owner_name", "蒼白");
        ::setup();
}
