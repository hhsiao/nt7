// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("哦我餓哦[2;37;0m[2;37;0m", ({"oiowe"}));        
        set("gender", "男性");                
        set("long", "哦我餓哦[2;37;0m
它是蒼狼的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "feel");
        set("owner_name", "蒼狼");
        set_temp("owner", "feel");
        set_temp("owner_name", "蒼狼");
        ::setup();
}
