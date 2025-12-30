// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m避水金睛獸[2;37;0m[2;37;0m", ({"fhh"}));        
        set("gender", "男性");                
        set("long", "超現實魔幻主義。[2;37;0m
它是紫薯蛋撻的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xmotoboy");
        set("owner_name", "紫薯蛋撻");
        set_temp("owner", "xmotoboy");
        set_temp("owner_name", "紫薯蛋撻");
        ::setup();
}
