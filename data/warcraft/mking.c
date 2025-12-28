// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m睡袋[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "居家旅行必備之物。[2;37;0m
它是亞瑟王的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "mking");
        set("owner_name", "亞瑟王");
        set_temp("owner", "mking");
        set_temp("owner_name", "亞瑟王");
        ::setup();
}
