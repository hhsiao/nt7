// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小眼[2;37;0m[2;37;0m", ({"myzuoqi"}));        
        set("gender", "女性");                
        set("long", "小眼[2;37;0m
它是精靈傢伙的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "nnnn");
        set("owner_name", "精靈傢伙");
        set_temp("owner", "nnnn");
        set_temp("owner_name", "精靈傢伙");
        ::setup();
}
