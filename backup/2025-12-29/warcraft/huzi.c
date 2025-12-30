// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("飛龍在天[2;37;0m[2;37;0m", ({"daibu"}));        
        set("gender", "女性");                
        set("long", "還可以[2;37;0m
它是丁三哥的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "huzi");
        set("owner_name", "丁三哥");
        set_temp("owner", "huzi");
        set_temp("owner_name", "丁三哥");
        ::setup();
}
