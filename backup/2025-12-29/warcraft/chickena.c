// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "女性");                
        set("long", "青龍[2;37;0m
它是啊一的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "chickena");
        set("owner_name", "啊一");
        set_temp("owner", "chickena");
        set_temp("owner_name", "啊一");
        ::setup();
}
