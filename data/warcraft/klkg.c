// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("加上大[2;37;0m[2;37;0m", ({"asdahjqwe"}));        
        set("gender", "男性");                
        set("long", "加上大[2;37;0m
它是卡薩打死的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "klkg");
        set("owner_name", "卡薩打死");
        set_temp("owner", "klkg");
        set_temp("owner_name", "卡薩打死");
        ::setup();
}
