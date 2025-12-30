// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("最愛白虎[2;37;0m[2;37;0m", ({"hlclabh"}));        
        set("gender", "女性");                
        set("long", "最愛白虎[2;37;0m
它是白虎一號的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "hlcla");
        set("owner_name", "白虎一號");
        set_temp("owner", "hlcla");
        set_temp("owner_name", "白虎一號");
        ::setup();
}
