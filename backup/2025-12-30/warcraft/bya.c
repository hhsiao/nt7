// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"pet"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是趙靈的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "bya");
        set("owner_name", "趙靈");
        set_temp("owner", "bya");
        set_temp("owner_name", "趙靈");
        ::setup();
}
