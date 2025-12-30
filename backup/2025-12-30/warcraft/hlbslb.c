// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("鳥[2;37;0m[2;37;0m", ({"niao"}));        
        set("gender", "女性");                
        set("long", "鳥[2;37;0m
它是睡蘿蔔的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "hlbslb");
        set("owner_name", "睡蘿蔔");
        set_temp("owner", "hlbslb");
        set_temp("owner_name", "睡蘿蔔");
        ::setup();
}
