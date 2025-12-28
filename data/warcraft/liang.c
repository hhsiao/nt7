// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m皮娃娃[5m[1;37m李澤楷[2;37;0m[2;37;0m", ({"car"}));        
        set("gender", "男性");                
        set("long", "這是淘寶熱銷的李澤楷版皮娃娃，讓你爽到爆，引無數少女爭賣腎。[2;37;0m
它是梁洛施的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "liang");
        set("owner_name", "梁洛施");
        set_temp("owner", "liang");
        set_temp("owner_name", "梁洛施");
        ::setup();
}
