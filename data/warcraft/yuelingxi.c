// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("學海無涯[2;37;0m[2;37;0m", ({"lingxi"}));        
        set("gender", "男性");                
        set("long", "學海無涯[2;37;0m
它是月靈犀的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yuelingxi");
        set("owner_name", "月靈犀");
        set_temp("owner", "yuelingxi");
        set_temp("owner_name", "月靈犀");
        ::setup();
}
