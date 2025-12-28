// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m龍王火[2;37;0m[2;37;0m", ({"qdds"}));        
        set("gender", "男性");                
        set("long", "龍王火，火龍王，龍王火起最難防。[2;37;0m
它是七燈大師的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "qideng");
        set("owner_name", "七燈大師");
        set_temp("owner", "qideng");
        set_temp("owner_name", "七燈大師");
        ::setup();
}
