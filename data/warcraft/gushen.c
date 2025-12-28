// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m逢賭必贏神龍[2;37;0m[2;37;0m", ({"gushenpet"}));        
        set("gender", "女性");                
        set("long", "一隻能讓主人逢賭必贏的神龍[2;37;0m
它是股神的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "gushen");
        set("owner_name", "股神");
        set_temp("owner", "gushen");
        set_temp("owner_name", "股神");
        ::setup();
}
