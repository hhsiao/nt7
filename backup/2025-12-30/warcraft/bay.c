// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m嘯天[2;37;0m[2;37;0m", ({"yutian"}));        
        set("gender", "男性");                
        set("long", "嘯天[2;37;0m
它是楓無的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "bay");
        set("owner_name", "楓無");
        set_temp("owner", "bay");
        set_temp("owner_name", "楓無");
        ::setup();
}
