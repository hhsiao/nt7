// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[36m青龍[2;37;0m[2;37;0m", ({"qlong"}));        
        set("gender", "女性");                
        set("long", "青龍[2;37;0m
它是丁鐺的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ddang");
        set("owner_name", "丁鐺");
        set_temp("owner", "ddang");
        set_temp("owner_name", "丁鐺");
        ::setup();
}
