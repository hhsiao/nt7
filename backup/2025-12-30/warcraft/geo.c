// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m天帝麒麟[2;37;0m[2;37;0m", ({"dst"}));        
        set("gender", "男性");                
        set("long", "天帝麒麟[2;37;0m
它是帝釋天的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "geo");
        set("owner_name", "帝釋天");
        set_temp("owner", "geo");
        set_temp("owner_name", "帝釋天");
        ::setup();
}
