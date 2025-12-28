// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("御劍乘風來[2;37;0m[2;37;0m", ({"lvlely"}));        
        set("gender", "女性");                
        set("long", "除魔天地間[2;37;0m
它是高處腎寒的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lunely");
        set("owner_name", "高處腎寒");
        set_temp("owner", "lunely");
        set_temp("owner_name", "高處腎寒");
        ::setup();
}
