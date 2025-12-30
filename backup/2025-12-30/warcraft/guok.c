// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("烏龜[2;37;0m[2;37;0m", ({"wgui"}));        
        set("gender", "男性");                
        set("long", "烏龜[2;37;0m
它是過客的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "guok");
        set("owner_name", "過客");
        set_temp("owner", "guok");
        set_temp("owner_name", "過客");
        ::setup();
}
