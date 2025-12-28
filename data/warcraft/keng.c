// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m馬[2;37;0m[2;37;0m", ({"pferd"}));        
        set("gender", "男性");                
        set("long", "$HIR$馬[2;37;0m
它是坑爹的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "keng");
        set("owner_name", "坑爹");
        set_temp("owner", "keng");
        set_temp("owner_name", "坑爹");
        ::setup();
}
