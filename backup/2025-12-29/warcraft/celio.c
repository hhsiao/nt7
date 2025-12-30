// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m黃金聖龍[2;37;0m[2;37;0m", ({"shenglong"}));        
        set("gender", "男性");                
        set("long", "一直渾身散發著陣陣龍威的聖龍。[2;37;0m
它是獨孤木木的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "celio");
        set("owner_name", "獨孤木木");
        set_temp("owner", "celio");
        set_temp("owner_name", "獨孤木木");
        ::setup();
}
