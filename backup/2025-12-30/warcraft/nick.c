// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m火麒麟[2;37;0m[2;37;0m", ({"lin"}));        
        set("gender", "男性");                
        set("long", "火麒麟[2;37;0m
它是枯榮大師的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "nick");
        set("owner_name", "枯榮大師");
        set_temp("owner", "nick");
        set_temp("owner_name", "枯榮大師");
        ::setup();
}
