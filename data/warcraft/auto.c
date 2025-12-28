// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m古小龍[2;37;0m[2;37;0m", ({"gulong"}));        
        set("gender", "男性");                
        set("long", "$HIC$古小龍[2;37;0m
它是古龍的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "auto");
        set("owner_name", "古龍");
        set_temp("owner", "auto");
        set_temp("owner_name", "古龍");
        ::setup();
}
