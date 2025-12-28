// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("的我[2;37;0m[2;37;0m", ({"lppp"}));        
        set("gender", "男性");                
        set("long", "的我[2;37;0m
它是恆一的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "zzha");
        set("owner_name", "恆一");
        set_temp("owner", "zzha");
        set_temp("owner_name", "恆一");
        ::setup();
}
