// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m烏雲[5m[1;37m蓋雪[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "這匹西域神駒通體雪白，只是馬背黑色如雲，神駿非常。[2;37;0m
它是馬千里的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "map");
        set("owner_name", "馬千里");
        set_temp("owner", "map");
        set_temp("owner_name", "馬千里");
        ::setup();
}
