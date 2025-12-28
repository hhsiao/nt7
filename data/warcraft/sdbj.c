// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白光虎[2;37;0m[2;37;0m", ({"sdbja"}));        
        set("gender", "男性");                
        set("long", "相當神秘[2;37;0m
它是天空十號的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "sdbj");
        set("owner_name", "天空十號");
        set_temp("owner", "sdbj");
        set_temp("owner_name", "天空十號");
        ::setup();
}
