// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m鋼鐵裝甲[2;37;0m[2;37;0m", ({"tank"}));        
        set("gender", "男性");                
        set("long", "鋼鐵裝甲[2;37;0m
它是零零一的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "agenti");
        set("owner_name", "零零一");
        set_temp("owner", "agenti");
        set_temp("owner_name", "零零一");
        ::setup();
}
