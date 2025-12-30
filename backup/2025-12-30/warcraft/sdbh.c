// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白光虎[2;37;0m[2;37;0m", ({"sdbha"}));        
        set("gender", "女性");                
        set("long", "相當神秘[2;37;0m
它是天空八號的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "sdbh");
        set("owner_name", "天空八號");
        set_temp("owner", "sdbh");
        set_temp("owner_name", "天空八號");
        ::setup();
}
