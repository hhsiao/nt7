// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("哈哈[2;37;0m[2;37;0m", ({"hahaha"}));        
        set("gender", "男性");                
        set("long", "好[2;37;0m
它是特務的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "cyjeff");
        set("owner_name", "特務");
        set_temp("owner", "cyjeff");
        set_temp("owner_name", "特務");
        ::setup();
}
