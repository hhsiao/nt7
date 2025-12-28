// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白虎[2;37;0m[2;37;0m", ({"huhu"}));        
        set("gender", "女性");                
        set("long", "大[2;37;0m
它是長二安的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "changansld");
        set("owner_name", "長二安");
        set_temp("owner", "changansld");
        set_temp("owner_name", "長二安");
        ::setup();
}
