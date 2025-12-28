// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("東方巨龍[2;37;0m[2;37;0m", ({"long"}));        
        set("gender", "女性");                
        set("long", "無所不能的東方巨龍。[2;37;0m
它是高不勝寒的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lonely");
        set("owner_name", "高不勝寒");
        set_temp("owner", "lonely");
        set_temp("owner_name", "高不勝寒");
        ::setup();
}
