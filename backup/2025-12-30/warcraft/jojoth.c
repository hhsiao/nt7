// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m飛劍[2;37;0m[2;37;0m", ({"feijian"}));        
        set("gender", "男性");                
        set("long", "一把靈劍。[2;37;0m
它是黃易的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "jojoth");
        set("owner_name", "黃易");
        set_temp("owner", "jojoth");
        set_temp("owner_name", "黃易");
        ::setup();
}
