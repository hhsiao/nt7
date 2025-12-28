// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m浴血重生[2;37;0m[2;37;0m", ({"moneys"}));        
        set("gender", "女性");                
        set("long", "浴血重生[2;37;0m
它是錢小賊的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "money");
        set("owner_name", "錢小賊");
        set_temp("owner", "money");
        set_temp("owner_name", "錢小賊");
        ::setup();
}
