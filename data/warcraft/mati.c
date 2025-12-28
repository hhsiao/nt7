// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m貳武[2;37;0m[2;37;0m", ({"matipet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是武貳的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "mati");
        set("owner_name", "武貳");
        set_temp("owner", "mati");
        set_temp("owner_name", "武貳");
        ::setup();
}
