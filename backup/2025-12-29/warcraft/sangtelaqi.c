// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("馬[2;37;0m[2;37;0m", ({"jkw"}));        
        set("gender", "男性");                
        set("long", "馬[2;37;0m
它是萬里無雲的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "sangtelaqi");
        set("owner_name", "萬里無雲");
        set_temp("owner", "sangtelaqi");
        set_temp("owner_name", "萬里無雲");
        ::setup();
}
