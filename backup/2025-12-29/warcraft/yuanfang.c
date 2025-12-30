// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m狄仁傑[2;37;0m[2;37;0m", ({"jie"}));        
        set("gender", "男性");                
        set("long", "狄仁傑[2;37;0m
它是元芳的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yuanfang");
        set("owner_name", "元芳");
        set_temp("owner", "yuanfang");
        set_temp("owner_name", "元芳");
        ::setup();
}
