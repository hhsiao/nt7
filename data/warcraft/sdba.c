// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白光虎[2;37;0m[2;37;0m", ({"drop_coin"}));        
        set("gender", "男性");                
        set("long", "相當神秘[2;37;0m
它是天空一號的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "sdba");
        set("owner_name", "天空一號");
        set_temp("owner", "sdba");
        set_temp("owner_name", "天空一號");
        ::setup();
}
