// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m火德星君[2;37;0m[2;37;0m", ({"sparker"}));        
        set("gender", "女性");                
        set("long", "火鳥[2;37;0m
它是鐵蛋的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "spark");
        set("owner_name", "鐵蛋");
        set_temp("owner", "spark");
        set_temp("owner_name", "鐵蛋");
        ::setup();
}
