// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("血煞[2;37;0m[2;37;0m", ({"super"}));        
        set("gender", "男性");                
        set("long", "血煞[2;37;0m
它是無痕華的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "wujiwuji");
        set("owner_name", "無痕華");
        set_temp("owner", "wujiwuji");
        set_temp("owner_name", "無痕華");
        ::setup();
}
