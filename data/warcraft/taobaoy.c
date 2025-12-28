// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m餘額寶[2;37;0m[2;37;0m", ({"goldyi"}));        
        set("gender", "男性");                
        set("long", "餘額餘額，多乎哉，不多矣！[2;37;0m
它是淘寶太一的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "taobaoy");
        set("owner_name", "淘寶太一");
        set_temp("owner", "taobaoy");
        set_temp("owner_name", "淘寶太一");
        ::setup();
}
