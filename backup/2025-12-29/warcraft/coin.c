// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("戰爭狂龍[2;37;0m[2;37;0m", ({"war"}));        
        set("gender", "男性");                
        set("long", "來摸摸[2;37;0m
它是澄銅的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "coin");
        set("owner_name", "澄銅");
        set_temp("owner", "coin");
        set_temp("owner_name", "澄銅");
        ::setup();
}
