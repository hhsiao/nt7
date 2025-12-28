// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("仲[2;37;0m[2;37;0m", ({"wiowe"}));        
        set("gender", "女性");                
        set("long", "去[2;37;0m
它是無很無的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "woshizu");
        set("owner_name", "無很無");
        set_temp("owner", "woshizu");
        set_temp("owner_name", "無很無");
        ::setup();
}
