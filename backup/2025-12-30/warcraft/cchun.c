// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;34m烏雲[1;37m蓋雪[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "這匹神駒通體雪白，只是馬背黑色如雲，追風逐電、神駿非常。[2;37;0m
它是常遇春的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "cchun");
        set("owner_name", "常遇春");
        set_temp("owner", "cchun");
        set_temp("owner_name", "常遇春");
        ::setup();
}
