// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m斷[1;33m念[1;32m劍[2;37;0m[2;37;0m", ({"cannian"}));        
        set("gender", "女性");                
        set("long", "一把破劍[2;37;0m
它是花千骨的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "hqg");
        set("owner_name", "花千骨");
        set_temp("owner", "hqg");
        set_temp("owner_name", "花千骨");
        ::setup();
}
