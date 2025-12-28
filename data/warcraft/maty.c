// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m伍黃[2;37;0m[2;37;0m", ({"matypet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是黃伍的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "maty");
        set("owner_name", "黃伍");
        set_temp("owner", "maty");
        set_temp("owner_name", "黃伍");
        ::setup();
}
