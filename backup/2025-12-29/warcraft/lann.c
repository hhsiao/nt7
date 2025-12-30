// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"ddddd"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是玉濤的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lann");
        set("owner_name", "玉濤");
        set_temp("owner", "lann");
        set_temp("owner_name", "玉濤");
        ::setup();
}
