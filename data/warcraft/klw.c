// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("空明[2;37;0m[2;37;0m", ({"kla"}));        
        set("gender", "女性");                
        set("long", "這個[2;37;0m
它是孔令文的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "klw");
        set("owner_name", "孔令文");
        set_temp("owner", "klw");
        set_temp("owner_name", "孔令文");
        ::setup();
}
