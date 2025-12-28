// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"dsxsss"}));        
        set("gender", "女性");                
        set("long", "多少算術[2;37;0m
它是雲兒的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "yrh");
        set("owner_name", "雲兒");
        set_temp("owner", "yrh");
        set_temp("owner_name", "雲兒");
        ::setup();
}
