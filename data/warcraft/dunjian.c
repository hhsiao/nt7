// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m魔像飛[2;37;0m[2;37;0m", ({"feitian"}));        
        set("gender", "男性");                
        set("long", "飛天魔像[2;37;0m
它是鈍劍的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "dunjian");
        set("owner_name", "鈍劍");
        set_temp("owner", "dunjian");
        set_temp("owner_name", "鈍劍");
        ::setup();
}
