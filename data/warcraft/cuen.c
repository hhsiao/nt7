// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"pet"}));        
        set("gender", "女性");                
        set("long", "青龍[2;37;0m
它是靈寸的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "cuen");
        set("owner_name", "靈寸");
        set_temp("owner", "cuen");
        set_temp("owner_name", "靈寸");
        ::setup();
}
