// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小眼[2;37;0m[2;37;0m", ({"myzuoqi"}));        
        set("gender", "女性");                
        set("long", "小眼[2;37;0m
它是皮皮慪氣的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "nnh");
        set("owner_name", "皮皮慪氣");
        set_temp("owner", "nnh");
        set_temp("owner_name", "皮皮慪氣");
        ::setup();
}
