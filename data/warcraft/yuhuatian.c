// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m雨師[2;37;0m[2;37;0m", ({"yushi"}));        
        set("gender", "男性");                
        set("long", "沒什麼特別的[2;37;0m
它是雨化田的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "yuhuatian");
        set("owner_name", "雨化田");
        set_temp("owner", "yuhuatian");
        set_temp("owner_name", "雨化田");
        ::setup();
}
