// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[35m墨魚[2;37;0m[2;37;0m", ({"mql"}));        
        set("gender", "男性");                
        set("long", "墨魚墨魚[2;37;0m
它是遙甲的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "uliann");
        set("owner_name", "遙甲");
        set_temp("owner", "uliann");
        set_temp("owner_name", "遙甲");
        ::setup();
}
