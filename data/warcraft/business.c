// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m招財[2;37;0m[2;37;0m", ({"zhaocai"}));        
        set("gender", "男性");                
        set("long", "招財納福[2;37;0m
它是商務的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "business");
        set("owner_name", "商務");
        set_temp("owner", "business");
        set_temp("owner_name", "商務");
        ::setup();
}
