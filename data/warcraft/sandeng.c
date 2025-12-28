// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m阿拉丁[2;37;0m[2;37;0m", ({"sdds"}));        
        set("gender", "男性");                
        set("long", "阿拉丁神燈。[2;37;0m
它是三燈大師的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "sandeng");
        set("owner_name", "三燈大師");
        set_temp("owner", "sandeng");
        set_temp("owner_name", "三燈大師");
        ::setup();
}
