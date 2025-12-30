// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m揮[31m盡[1;32m趙[34m雲[1;33m[2;37;0m[2;37;0m", ({"wolf"}));        
        set("gender", "男性");                
        set("long", "王王[2;37;0m
它是洪二公的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "gba");
        set("owner_name", "洪二公");
        set_temp("owner", "gba");
        set_temp("owner_name", "洪二公");
        ::setup();
}
