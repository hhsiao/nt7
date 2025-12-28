// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("老馬[2;37;0m[2;37;0m", ({"laom"}));        
        set("gender", "女性");                
        set("long", "老馬[2;37;0m
它是竹籬笆的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "yqsmia");
        set("owner_name", "竹籬笆");
        set_temp("owner", "yqsmia");
        set_temp("owner_name", "竹籬笆");
        ::setup();
}
