// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("自行車[2;37;0m[2;37;0m", ({"zxcc"}));        
        set("gender", "男性");                
        set("long", "自行車[2;37;0m
它是雍麗風的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "nighebftk");
        set("owner_name", "雍麗風");
        set_temp("owner", "nighebftk");
        set_temp("owner_name", "雍麗風");
        ::setup();
}
