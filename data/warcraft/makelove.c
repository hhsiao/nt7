// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m白虎[2;37;0m[2;37;0m", ({"long"}));        
        set("gender", "男性");                
        set("long", "$HIW$白虎[2;37;0m
它是東門官人的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "makelove");
        set("owner_name", "東門官人");
        set_temp("owner", "makelove");
        set_temp("owner_name", "東門官人");
        ::setup();
}
