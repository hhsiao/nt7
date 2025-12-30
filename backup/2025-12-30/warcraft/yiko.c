// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m雲夢[2;37;0m[2;37;0m", ({"asd"}));        
        set("gender", "男性");                
        set("long", "雲夢[2;37;0m
它是盧雲的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yiko");
        set("owner_name", "盧雲");
        set_temp("owner", "yiko");
        set_temp("owner_name", "盧雲");
        ::setup();
}
