// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[31m飛天[1;37m神獸[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "$BLINK$$RED$飛天$HIW$神獸[2;37;0m
它是發電機的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "topa");
        set("owner_name", "發電機");
        set_temp("owner", "topa");
        set_temp("owner_name", "發電機");
        ::setup();
}
