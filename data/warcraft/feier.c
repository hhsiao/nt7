// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("潛水艇[2;37;0m[2;37;0m", ({"ioi"}));        
        set("gender", "男性");                
        set("long", "good[2;37;0m
它是獨孤求拜的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "feier");
        set("owner_name", "獨孤求拜");
        set_temp("owner", "feier");
        set_temp("owner_name", "獨孤求拜");
        ::setup();
}
