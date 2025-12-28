// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"shou"}));        
        set("gender", "女性");                
        set("long", "。。。。[2;37;0m
它是玉露的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "sana");
        set("owner_name", "玉露");
        set_temp("owner", "sana");
        set_temp("owner_name", "玉露");
        ::setup();
}
