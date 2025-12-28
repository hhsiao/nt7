// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m草泥馬[2;37;0m[2;37;0m[2;37;0m", ({"nima"}));        
        set("gender", "女性");                
        set("long", "這是一隻羊駝！[2;37;0m
它是段思平的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "six");
        set("owner_name", "段思平");
        set_temp("owner", "six");
        set_temp("owner_name", "段思平");
        ::setup();
}
