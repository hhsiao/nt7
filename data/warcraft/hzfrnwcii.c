// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("自行車[2;37;0m[2;37;0m", ({"zxcc"}));        
        set("gender", "男性");                
        set("long", "自行車[2;37;0m
它是毋理默的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "hzfrnwcii");
        set("owner_name", "毋理默");
        set_temp("owner", "hzfrnwcii");
        set_temp("owner_name", "毋理默");
        ::setup();
}
