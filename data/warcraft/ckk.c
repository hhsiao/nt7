// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("錢[2;37;0m[2;37;0m", ({"ooo"}));        
        set("gender", "女性");                
        set("long", "錢[2;37;0m
它是令狐不衝的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ckk");
        set("owner_name", "令狐不衝");
        set_temp("owner", "ckk");
        set_temp("owner_name", "令狐不衝");
        ::setup();
}
