// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m乾龍[2;37;0m[2;37;0m", ({"qianlong"}));        
        set("gender", "男性");                
        set("long", "厲害的喲[2;37;0m
它是紅花的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "redflower");
        set("owner_name", "紅花");
        set_temp("owner", "redflower");
        set_temp("owner_name", "紅花");
        ::setup();
}
