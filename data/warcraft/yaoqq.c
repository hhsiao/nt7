// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"yaoqqq"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是藥球球的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yaoqq");
        set("owner_name", "藥球球");
        set_temp("owner", "yaoqq");
        set_temp("owner_name", "藥球球");
        ::setup();
}
