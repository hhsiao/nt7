// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("老胡老過戶[2;37;0m[2;37;0m", ({"jianhua"}));        
        set("gender", "男性");                
        set("long", "老胡老過戶[2;37;0m
它是何劍華的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "hejh");
        set("owner_name", "何劍華");
        set_temp("owner", "hejh");
        set_temp("owner_name", "何劍華");
        ::setup();
}
