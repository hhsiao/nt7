// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m烏雲[1;37m蓋雪[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "這匹西域神駒通體雪白，只是馬背黑色如雲，神駿非常。[2;37;0m
它是楊玉環的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yuhuan");
        set("owner_name", "楊玉環");
        set_temp("owner", "yuhuan");
        set_temp("owner_name", "楊玉環");
        ::setup();
}
