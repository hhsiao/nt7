// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("米多神獸[2;37;0m[2;37;0m", ({"miduoride"}));        
        set("gender", "男性");                
        set("long", "米多神獸[2;37;0m
它是米多六的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "minduolinf");
        set("owner_name", "米多六");
        set_temp("owner", "minduolinf");
        set_temp("owner_name", "米多六");
        ::setup();
}
