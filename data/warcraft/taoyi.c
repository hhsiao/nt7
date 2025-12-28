// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("一木[2;37;0m[2;37;0m", ({"daoyi"}));        
        set("gender", "男性");                
        set("long", "choose 4[2;37;0m
它是桃花朵開的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "taoyi");
        set("owner_name", "桃花朵開");
        set_temp("owner", "taoyi");
        set_temp("owner_name", "桃花朵開");
        ::setup();
}
