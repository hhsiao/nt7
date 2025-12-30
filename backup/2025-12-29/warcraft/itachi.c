// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("幻龍[2;37;0m[2;37;0m", ({"shou"}));        
        set("gender", "男性");                
        set("long", "勇猛無比[2;37;0m
它是段雨龍的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "itachi");
        set("owner_name", "段雨龍");
        set_temp("owner", "itachi");
        set_temp("owner_name", "段雨龍");
        ::setup();
}
