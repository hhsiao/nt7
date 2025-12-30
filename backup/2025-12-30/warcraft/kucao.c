// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("雀兒[2;37;0m[2;37;0m", ({"queer"}));        
        set("gender", "女性");                
        set("long", "這是一隻可愛的小鳥。[2;37;0m
它是枯草的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "kucao");
        set("owner_name", "枯草");
        set_temp("owner", "kucao");
        set_temp("owner_name", "枯草");
        ::setup();
}
