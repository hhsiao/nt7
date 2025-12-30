// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("紅色[2;37;0m[2;37;0m", ({"kaikai"}));        
        set("gender", "男性");                
        set("long", "王曉凱[2;37;0m
它是為誰瘋狂的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "skillss");
        set("owner_name", "為誰瘋狂");
        set_temp("owner", "skillss");
        set_temp("owner_name", "為誰瘋狂");
        ::setup();
}
