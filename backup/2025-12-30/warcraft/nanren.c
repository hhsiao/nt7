// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"long"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是男人的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "nanren");
        set("owner_name", "男人");
        set_temp("owner", "nanren");
        set_temp("owner_name", "男人");
        ::setup();
}
