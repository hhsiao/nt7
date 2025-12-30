// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("虎虎虎[2;37;0m[2;37;0m", ({"avtiger"}));        
        set("gender", "男性");                
        set("long", "虎虎虎[2;37;0m
它是蒼老師的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "avone");
        set("owner_name", "蒼老師");
        set_temp("owner", "avone");
        set_temp("owner_name", "蒼老師");
        ::setup();
}
