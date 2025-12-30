// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[30m中華[1;33m小龍[2;37;0m[2;37;0m", ({"binbin"}));        
        set("gender", "男性");                
        set("long", "這是伴隨小純一起成長的青龍獸[2;37;0m
它是小純的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "bin");
        set("owner_name", "小純");
        set_temp("owner", "bin");
        set_temp("owner_name", "小純");
        ::setup();
}
