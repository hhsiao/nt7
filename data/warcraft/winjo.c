// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m冰[1;36m甲[1;36m龍[1;36m痕[2;37;0m[2;37;0m", ({"hoho"}));        
        set("gender", "男性");                
        set("long", "冰甲龍痕[2;37;0m
它是劍之初的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "winjo");
        set("owner_name", "劍之初");
        set_temp("owner", "winjo");
        set_temp("owner_name", "劍之初");
        ::setup();
}
