// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("避血晶晶獸[2;37;0m[2;37;0m", ({"bibo"}));        
        set("gender", "男性");                
        set("long", "一頭龐然大物[2;37;0m
它是歐陽西克的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "upper");
        set("owner_name", "歐陽西克");
        set_temp("owner", "upper");
        set_temp("owner_name", "歐陽西克");
        ::setup();
}
