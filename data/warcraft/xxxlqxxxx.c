// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m靈塔武痴[2;37;0m[2;37;0m", ({"xxxx"}));        
        set("gender", "女性");                
        set("long", "塔上掉下來的武痴！[2;37;0m
它是靈塔囚徒的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xxxlqxxxx");
        set("owner_name", "靈塔囚徒");
        set_temp("owner", "xxxlqxxxx");
        set_temp("owner_name", "靈塔囚徒");
        ::setup();
}
