// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"xiaoq"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是書書的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "kkya");
        set("owner_name", "書書");
        set_temp("owner", "kkya");
        set_temp("owner_name", "書書");
        ::setup();
}
