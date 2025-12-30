// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m庫賤[2;37;0m[2;37;0m", ({"koszxcpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是賤庫的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "koszxc");
        set("owner_name", "賤庫");
        set_temp("owner", "koszxc");
        set_temp("owner_name", "賤庫");
        ::setup();
}
