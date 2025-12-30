// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔幻獸[2;37;0m[2;37;0m", ({"xxdfs"}));        
        set("gender", "男性");                
        set("long", "魔幻獸[2;37;0m
它是習習的風的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xxdf");
        set("owner_name", "習習的風");
        set_temp("owner", "xxdf");
        set_temp("owner_name", "習習的風");
        ::setup();
}
