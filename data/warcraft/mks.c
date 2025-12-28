// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m四海[1;37m游龍[2;37;0m[2;37;0m", ({"dragonx"}));        
        set("gender", "女性");                
        set("long", "一條龍[2;37;0m
它是有殺氣的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "mks");
        set("owner_name", "有殺氣");
        set_temp("owner", "mks");
        set_temp("owner_name", "有殺氣");
        ::setup();
}
