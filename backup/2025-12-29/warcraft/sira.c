// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("龍[2;37;0m[2;37;0m", ({"aris"}));        
        set("gender", "男性");                
        set("long", "按時地方[2;37;0m
它是趙瑟的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "sira");
        set("owner_name", "趙瑟");
        set_temp("owner", "sira");
        set_temp("owner_name", "趙瑟");
        ::setup();
}
