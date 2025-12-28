// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("下樹[2;37;0m[2;37;0m", ({"xiashu"}));        
        set("gender", "男性");                
        set("long", "下樹[2;37;0m
它是子提的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ziti");
        set("owner_name", "子提");
        set_temp("owner", "ziti");
        set_temp("owner_name", "子提");
        ::setup();
}
