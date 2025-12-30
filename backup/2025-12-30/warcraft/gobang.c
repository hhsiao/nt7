// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("幫共[2;37;0m[2;37;0m", ({"banggo"}));        
        set("gender", "女性");                
        set("long", "幫共[2;37;0m
它是共幫的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "gobang");
        set("owner_name", "共幫");
        set_temp("owner", "gobang");
        set_temp("owner_name", "共幫");
        ::setup();
}
