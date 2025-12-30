// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m皮娃娃[5m[1;37m梁錦松[2;37;0m[2;37;0m", ({"car"}));        
        set("gender", "男性");                
        set("long", "這是淘寶熱銷的梁錦松版皮娃娃，引眾多少女爭相賣腎，閨房必備。[2;37;0m
它是郭晶晶的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "gjj");
        set("owner_name", "郭晶晶");
        set_temp("owner", "gjj");
        set_temp("owner_name", "郭晶晶");
        ::setup();
}
