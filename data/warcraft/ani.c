// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m紅布袋[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "紅布袋[2;37;0m
它是書書的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ani");
        set("owner_name", "書書");
        set_temp("owner", "ani");
        set_temp("owner_name", "書書");
        ::setup();
}
