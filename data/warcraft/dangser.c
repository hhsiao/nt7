// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m時而[2;37;0m[2;37;0m", ({"shier"}));        
        set("gender", "男性");                
        set("long", "時而[2;37;0m
它是食餌不化的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "dangser");
        set("owner_name", "食餌不化");
        set_temp("owner", "dangser");
        set_temp("owner_name", "食餌不化");
        ::setup();
}
