// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("鏢旗[2;37;0m[2;37;0m", ({"xbiaoshia"}));        
        set("gender", "女性");                
        set("long", "這是一杆鏢旗[2;37;0m
它是鏢師一的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "biaoshia");
        set("owner_name", "鏢師一");
        set_temp("owner", "biaoshia");
        set_temp("owner_name", "鏢師一");
        ::setup();
}
