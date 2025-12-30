// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白狐[2;37;0m[2;37;0m", ({"baihu"}));        
        set("gender", "男性");                
        set("long", "白[2;37;0m
它是風月無邊的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "fengyue");
        set("owner_name", "風月無邊");
        set_temp("owner", "fengyue");
        set_temp("owner_name", "風月無邊");
        ::setup();
}
