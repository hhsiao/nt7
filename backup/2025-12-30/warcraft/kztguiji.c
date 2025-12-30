// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("飛龍[2;37;0m[2;37;0m", ({"baoma"}));        
        set("gender", "男性");                
        set("long", "飛龍在天[2;37;0m
它是六脈無劍的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "kztguiji");
        set("owner_name", "六脈無劍");
        set_temp("owner", "kztguiji");
        set_temp("owner_name", "六脈無劍");
        ::setup();
}
