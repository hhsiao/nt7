// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m白虎[2;37;0m[2;37;0m", ({"tiger"}));        
        set("gender", "男性");                
        set("long", "幻獸[2;37;0m
它是蕭柯的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "bykknd");
        set("owner_name", "蕭柯");
        set_temp("owner", "bykknd");
        set_temp("owner_name", "蕭柯");
        ::setup();
}
