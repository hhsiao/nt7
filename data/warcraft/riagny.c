// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("怪獸[2;37;0m[2;37;0m", ({"kill"}));        
        set("gender", "女性");                
        set("long", "這是一隻[2;37;0m
它是鐵衣的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "riagny");
        set("owner_name", "鐵衣");
        set_temp("owner", "riagny");
        set_temp("owner_name", "鐵衣");
        ::setup();
}
