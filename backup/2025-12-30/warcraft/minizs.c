// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m玄武大帝[2;37;0m[2;37;0m", ({"minizsshou"}));        
        set("gender", "男性");                
        set("long", "四大神獸[2;37;0m
它是絕色的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "minizs");
        set("owner_name", "絕色");
        set_temp("owner", "minizs");
        set_temp("owner_name", "絕色");
        ::setup();
}
