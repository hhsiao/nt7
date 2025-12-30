// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("龍[2;37;0m[2;37;0m", ({"long"}));        
        set("gender", "男性");                
        set("long", "龍[2;37;0m
它是護腕師傅的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "iwrists");
        set("owner_name", "護腕師傅");
        set_temp("owner", "iwrists");
        set_temp("owner_name", "護腕師傅");
        ::setup();
}
