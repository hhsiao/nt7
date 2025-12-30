// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白虎[2;37;0m[2;37;0m", ({"baihu"}));        
        set("gender", "男性");                
        set("long", "白虎[2;37;0m
它是元不諱的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "kftc");
        set("owner_name", "元不諱");
        set_temp("owner", "kftc");
        set_temp("owner_name", "元不諱");
        ::setup();
}
