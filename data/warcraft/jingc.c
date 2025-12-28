// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("王獸[2;37;0m[2;37;0m", ({"shoushou"}));        
        set("gender", "女性");                
        set("long", "王獸[2;37;0m
它是靜三的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "jingc");
        set("owner_name", "靜三");
        set_temp("owner", "jingc");
        set_temp("owner_name", "靜三");
        ::setup();
}
