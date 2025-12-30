// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m藍火[2;37;0m[2;37;0m", ({"flym"}));        
        set("gender", "女性");                
        set("long", "藍火[2;37;0m
它是風飛的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "maplefly");
        set("owner_name", "風飛");
        set_temp("owner", "maplefly");
        set_temp("owner_name", "風飛");
        ::setup();
}
