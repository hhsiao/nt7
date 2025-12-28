// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("因量[2;37;0m[2;37;0m", ({"ldldld"}));        
        set("gender", "男性");                
        set("long", "膽大[2;37;0m
它是胃軲轆的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "wacaib");
        set("owner_name", "胃軲轆");
        set_temp("owner", "wacaib");
        set_temp("owner_name", "胃軲轆");
        ::setup();
}
