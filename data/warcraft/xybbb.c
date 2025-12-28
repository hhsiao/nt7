// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m騾子[2;37;0m[2;37;0m", ({"luozi"}));        
        set("gender", "女性");                
        set("long", "$HIB$騾子[2;37;0m
它是苦工貳的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xybbb");
        set("owner_name", "苦工貳");
        set_temp("owner", "xybbb");
        set_temp("owner_name", "苦工貳");
        ::setup();
}
