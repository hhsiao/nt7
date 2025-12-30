// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("升龍拳[2;37;0m[2;37;0m", ({"ryo"}));        
        set("gender", "男性");                
        set("long", "後有跟[2;37;0m
它是毀容的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "huirong");
        set("owner_name", "毀容");
        set_temp("owner", "huirong");
        set_temp("owner_name", "毀容");
        ::setup();
}
