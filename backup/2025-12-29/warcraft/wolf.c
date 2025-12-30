// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;33m嘯月[1;34m蒼狼[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "這頭妖狼體態健碩、面目猙獰，眼睛幽幽泛著藍光，令人毛骨悚然。[2;37;0m
它是雅各布的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "wolf");
        set("owner_name", "雅各布");
        set_temp("owner", "wolf");
        set_temp("owner_name", "雅各布");
        ::setup();
}
