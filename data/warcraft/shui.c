// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("義大利[2;37;0m[2;37;0m", ({"weieiei"}));        
        set("gender", "男性");                
        set("long", "國家[2;37;0m
它是水袋的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "shui");
        set("owner_name", "水袋");
        set_temp("owner", "shui");
        set_temp("owner_name", "水袋");
        ::setup();
}
