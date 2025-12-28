// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[35m極度[5m[1;33m誘[1;36m惑[2;37;0m[2;37;0m[2;37;0m", ({"lovely"}));        
        set("gender", "女性");                
        set("long", "極度誘惑![2;37;0m
它是清純小妞的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "evilvirgin");
        set("owner_name", "清純小妞");
        set_temp("owner", "evilvirgin");
        set_temp("owner_name", "清純小妞");
        ::setup();
}
