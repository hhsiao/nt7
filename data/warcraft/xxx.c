// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"que"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是土豆的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xxx");
        set("owner_name", "土豆");
        set_temp("owner", "xxx");
        set_temp("owner_name", "土豆");
        ::setup();
}
