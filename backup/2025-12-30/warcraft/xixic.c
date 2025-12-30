// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("次飛翔[2;37;0m[2;37;0m", ({"xixiccc"}));        
        set("gender", "女性");                
        set("long", "自由的飛翔[2;37;0m
它是習賜的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xixic");
        set("owner_name", "習賜");
        set_temp("owner", "xixic");
        set_temp("owner_name", "習賜");
        ::setup();
}
