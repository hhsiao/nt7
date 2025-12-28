// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[30m小錢包[2;37;0m[2;37;0m", ({"qianbaoa"}));        
        set("gender", "男性");                
        set("long", "$BLK$小錢包[2;37;0m
它是錢多多的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ana");
        set("owner_name", "錢多多");
        set_temp("owner", "ana");
        set_temp("owner_name", "錢多多");
        ::setup();
}
