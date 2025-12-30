// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("蘿莉[2;37;0m[2;37;0m", ({"slaalong"}));        
        set("gender", "男性");                
        set("long", "停權[2;37;0m
它是特摩的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "slaa");
        set("owner_name", "特摩");
        set_temp("owner", "slaa");
        set_temp("owner_name", "特摩");
        ::setup();
}
