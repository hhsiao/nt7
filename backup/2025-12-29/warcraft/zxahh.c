// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("血瞳[2;37;0m[2;37;0m", ({"xuetong"}));        
        set("gender", "男性");                
        set("long", "如血的雙瞳[2;37;0m
它是了盡的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zxahh");
        set("owner_name", "了盡");
        set_temp("owner", "zxahh");
        set_temp("owner_name", "了盡");
        ::setup();
}
