// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m劍齒虎[2;37;0m[2;37;0m", ({"tiger"}));        
        set("gender", "男性");                
        set("long", "遠古復活的神獸[2;37;0m
它是鐵兒的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "tier");
        set("owner_name", "鐵兒");
        set_temp("owner", "tier");
        set_temp("owner_name", "鐵兒");
        ::setup();
}
