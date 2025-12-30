// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m菲斯[2;37;0m[2;37;0m", ({"feith"}));        
        set("gender", "女性");                
        set("long", "狗堅強的英文名被佔用了。[2;37;0m
它是薇薇安的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "vivian");
        set("owner_name", "薇薇安");
        set_temp("owner", "vivian");
        set_temp("owner_name", "薇薇安");
        ::setup();
}
