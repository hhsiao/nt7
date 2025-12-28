// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("九尾靈貓[2;37;0m[2;37;0m", ({"myflycat"}));        
        set("gender", "女性");                
        set("long", "九尾靈貓[2;37;0m
它是靈郭的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "flycat");
        set("owner_name", "靈郭");
        set_temp("owner", "flycat");
        set_temp("owner_name", "靈郭");
        ::setup();
}
