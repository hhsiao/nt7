// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m太古[1;33m屎殼螂[2;37;0m[2;37;0m", ({"bugs"}));        
        set("gender", "女性");                
        set("long", "屎殼螂啊，太古的啊，臭氣熏天，臭不可聞，聞之即死。[2;37;0m
它是拱屎蟲的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "bug");
        set("owner_name", "拱屎蟲");
        set_temp("owner", "bug");
        set_temp("owner_name", "拱屎蟲");
        ::setup();
}
