// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "女性");                
        set("long", "青龍[2;37;0m
它是段煙雨的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xyfe");
        set("owner_name", "段煙雨");
        set_temp("owner", "xyfe");
        set_temp("owner_name", "段煙雨");
        ::setup();
}
