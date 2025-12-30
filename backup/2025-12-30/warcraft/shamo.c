// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("駱駝[2;37;0m[2;37;0m", ({"camel"}));        
        set("gender", "女性");                
        set("long", "沙漠之舟[2;37;0m
它是指間沙的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "shamo");
        set("owner_name", "指間沙");
        set_temp("owner", "shamo");
        set_temp("owner_name", "指間沙");
        ::setup();
}
