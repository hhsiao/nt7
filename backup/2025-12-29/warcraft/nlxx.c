// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m鳳凰[2;37;0m[2;37;0m", ({"bird"}));        
        set("gender", "女性");                
        set("long", "一隻美麗的鳳凰[2;37;0m
它是納蘭瀟瀟的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "nlxx");
        set("owner_name", "納蘭瀟瀟");
        set_temp("owner", "nlxx");
        set_temp("owner_name", "納蘭瀟瀟");
        ::setup();
}
