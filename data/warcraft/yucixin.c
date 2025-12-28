// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("傾雪[2;37;0m[2;37;0m", ({"qingxue"}));        
        set("gender", "男性");                
        set("long", "傾雪[2;37;0m
它是玉辭心的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yucixin");
        set("owner_name", "玉辭心");
        set_temp("owner", "yucixin");
        set_temp("owner_name", "玉辭心");
        ::setup();
}
