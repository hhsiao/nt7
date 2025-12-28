// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("神仙龍[2;37;0m[2;37;0m", ({"shengou"}));        
        set("gender", "男性");                
        set("long", "神仙龍[2;37;0m
它是嚨鳳的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "longfe");
        set("owner_name", "嚨鳳");
        set_temp("owner", "longfe");
        set_temp("owner_name", "嚨鳳");
        ::setup();
}
