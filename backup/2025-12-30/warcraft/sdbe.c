// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白光虎[2;37;0m[2;37;0m", ({"sdbea"}));        
        set("gender", "男性");                
        set("long", "相當神秘[2;37;0m
它是天空五號的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "sdbe");
        set("owner_name", "天空五號");
        set_temp("owner", "sdbe");
        set_temp("owner_name", "天空五號");
        ::setup();
}
