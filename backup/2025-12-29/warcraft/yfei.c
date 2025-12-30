// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;34m烏雲[1;37m蓋雪[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "這匹神駒通體雪白，只是馬背黑色如雲，追風逐電、神駿非常。[2;37;0m
它是岳飛的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yfei");
        set("owner_name", "岳飛");
        set_temp("owner", "yfei");
        set_temp("owner_name", "岳飛");
        ::setup();
}
