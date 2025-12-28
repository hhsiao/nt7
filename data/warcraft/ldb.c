// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m大白馬[2;37;0m[2;37;0m", ({"horse"}));        
        set("gender", "男性");                
        set("long", "純種[2;37;0m
它是呂洞賓的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ldb");
        set("owner_name", "呂洞賓");
        set_temp("owner", "ldb");
        set_temp("owner_name", "呂洞賓");
        ::setup();
}
