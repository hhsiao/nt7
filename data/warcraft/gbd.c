// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("說不得[2;37;0m[2;37;0m", ({"gbdlong"}));        
        set("gender", "男性");                
        set("long", "數額[2;37;0m
它是顧不得的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "gbd");
        set("owner_name", "顧不得");
        set_temp("owner", "gbd");
        set_temp("owner_name", "顧不得");
        ::setup();
}
