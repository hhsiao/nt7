// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m白虎[2;37;0m[2;37;0m", ({"whitetiger"}));        
        set("gender", "男性");                
        set("long", "白虎[2;37;0m
它是緋月的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "slem");
        set("owner_name", "緋月");
        set_temp("owner", "slem");
        set_temp("owner_name", "緋月");
        ::setup();
}
