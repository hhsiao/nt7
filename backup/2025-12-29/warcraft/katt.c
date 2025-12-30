// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("怪獸[2;37;0m[2;37;0m", ({"zhouy"}));        
        set("gender", "男性");                
        set("long", "大怪獸[2;37;0m
它是可可的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "katt");
        set("owner_name", "可可");
        set_temp("owner", "katt");
        set_temp("owner_name", "可可");
        ::setup();
}
