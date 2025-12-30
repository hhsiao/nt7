// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("墨玉碧麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "墨玉碧麒麟[2;37;0m
它是以太劍劍的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "etherh");
        set("owner_name", "以太劍劍");
        set_temp("owner", "etherh");
        set_temp("owner_name", "以太劍劍");
        ::setup();
}
