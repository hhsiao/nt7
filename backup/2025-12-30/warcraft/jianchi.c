// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m魔劍[2;37;0m[2;37;0m", ({"mojian"}));        
        set("gender", "男性");                
        set("long", "這把劍已經成為一隻魔獸！[2;37;0m
它是劍痴的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "jianchi");
        set("owner_name", "劍痴");
        set_temp("owner", "jianchi");
        set_temp("owner_name", "劍痴");
        ::setup();
}
