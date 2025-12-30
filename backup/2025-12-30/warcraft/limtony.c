// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("赤色[2;37;0m[2;37;0m", ({"cafe"}));        
        set("gender", "女性");                
        set("long", "六號[2;37;0m
它是咖啡六號的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "limtony");
        set("owner_name", "咖啡六號");
        set_temp("owner", "limtony");
        set_temp("owner_name", "咖啡六號");
        ::setup();
}
