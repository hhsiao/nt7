// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"dargon"}));        
        set("gender", "男性");                
        set("long", "一條青龍[2;37;0m
它是蘇黃的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "suhuang");
        set("owner_name", "蘇黃");
        set_temp("owner", "suhuang");
        set_temp("owner_name", "蘇黃");
        ::setup();
}
