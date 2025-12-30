// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m洛神鳥[2;37;0m[2;37;0m", ({"doo"}));        
        set("gender", "男性");                
        set("long", "坐騎[2;37;0m
它是齊洛仙的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "shar");
        set("owner_name", "齊洛仙");
        set_temp("owner", "shar");
        set_temp("owner_name", "齊洛仙");
        ::setup();
}
