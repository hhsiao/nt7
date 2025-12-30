// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"maaa"}));        
        set("gender", "女性");                
        set("long", "麒麟[2;37;0m
它是軒轅一的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "nba");
        set("owner_name", "軒轅一");
        set_temp("owner", "nba");
        set_temp("owner_name", "軒轅一");
        ::setup();
}
