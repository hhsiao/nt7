// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("愛瘋[2;37;0m[2;37;0m", ({"iphone"}));        
        set("gender", "女性");                
        set("long", "這是一臺愛瘋的五色版本，這個有富貴金[2;37;0m
它是喬布斯的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "ios");
        set("owner_name", "喬布斯");
        set_temp("owner", "ios");
        set_temp("owner_name", "喬布斯");
        ::setup();
}
