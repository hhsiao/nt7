// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"long"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是段譽的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wuzei");
        set("owner_name", "段譽");
        set_temp("owner", "wuzei");
        set_temp("owner_name", "段譽");
        ::setup();
}
