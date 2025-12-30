// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m色虎[2;37;0m[2;37;0m", ({"jinhu"}));        
        set("gender", "男性");                
        set("long", "$HIY$色虎[2;37;0m
它是郝劍刃的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "hscat");
        set("owner_name", "郝劍刃");
        set_temp("owner", "hscat");
        set_temp("owner_name", "郝劍刃");
        ::setup();
}
