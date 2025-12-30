// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[47;1m[34m烏雲踏雪[2;37;0m[2;37;0m", ({"wuyun"}));        
        set("gender", "女性");                
        set("long", "烏雲踏雪[2;37;0m
它是霧中樓的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "sss");
        set("owner_name", "霧中樓");
        set_temp("owner", "sss");
        set_temp("owner_name", "霧中樓");
        ::setup();
}
