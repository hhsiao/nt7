// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("遠古[2;37;0m[2;37;0m", ({"meccfpet"}));        
        set("gender", "男性");                
        set("long", "遠古[2;37;0m
它是阿蘭嘯的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "meccf");
        set("owner_name", "阿蘭嘯");
        set_temp("owner", "meccf");
        set_temp("owner_name", "阿蘭嘯");
        ::setup();
}
