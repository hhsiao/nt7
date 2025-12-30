// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("怡寶[2;37;0m[2;37;0m", ({"bao"}));        
        set("gender", "男性");                
        set("long", "怡寶[2;37;0m
它是逍黃的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xiaohuang");
        set("owner_name", "逍黃");
        set_temp("owner", "xiaohuang");
        set_temp("owner_name", "逍黃");
        ::setup();
}
