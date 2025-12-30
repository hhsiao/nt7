// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"xiaolong"}));        
        set("gender", "男性");                
        set("long", "神武[2;37;0m
它是天豬天的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "feitianzhu");
        set("owner_name", "天豬天");
        set_temp("owner", "feitianzhu");
        set_temp("owner_name", "天豬天");
        ::setup();
}
