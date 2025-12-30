// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[35m千幻[2;37;0m[2;37;0m", ({"dijun"}));        
        set("gender", "男性");                
        set("long", "呆呆的[2;37;0m
它是諸葛謹的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "linsu");
        set("owner_name", "諸葛謹");
        set_temp("owner", "linsu");
        set_temp("owner_name", "諸葛謹");
        ::setup();
}
