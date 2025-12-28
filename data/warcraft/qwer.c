// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("天樂龍[2;37;0m[2;37;0m", ({"ttlong"}));        
        set("gender", "女性");                
        set("long", "天樂龍[2;37;0m
它是黑雨的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "qwer");
        set("owner_name", "黑雨");
        set_temp("owner", "qwer");
        set_temp("owner_name", "黑雨");
        ::setup();
}
