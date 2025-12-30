// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m電毛驢[2;37;0m[2;37;0m", ({"coolong"}));        
        set("gender", "男性");                
        set("long", "$HIY$電毛驢[2;37;0m
它是襲風的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "coo");
        set("owner_name", "襲風");
        set_temp("owner", "coo");
        set_temp("owner_name", "襲風");
        ::setup();
}
