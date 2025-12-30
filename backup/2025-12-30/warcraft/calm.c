// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m磁懸浮[2;37;0m[2;37;0m", ({"magnetism"}));        
        set("gender", "女性");                
        set("long", "同性相斥，異性相吸！[2;37;0m
它是電感應的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "calm");
        set("owner_name", "電感應");
        set_temp("owner", "calm");
        set_temp("owner_name", "電感應");
        ::setup();
}
