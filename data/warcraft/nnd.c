// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小眼[2;37;0m[2;37;0m", ({"myzuoqi"}));        
        set("gender", "女性");                
        set("long", "小眼[2;37;0m
它是麵條出錯的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "nnd");
        set("owner_name", "麵條出錯");
        set_temp("owner", "nnd");
        set_temp("owner_name", "麵條出錯");
        ::setup();
}
