// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("啾啾擠擠[2;37;0m[2;37;0m", ({"myzuoqi"}));        
        set("gender", "女性");                
        set("long", "啾啾擠擠[2;37;0m
它是慢司的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "bbbn");
        set("owner_name", "慢司");
        set_temp("owner", "bbbn");
        set_temp("owner_name", "慢司");
        ::setup();
}
