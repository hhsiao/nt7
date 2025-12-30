// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("鳳狂靈[2;37;0m[2;37;0m", ({"fkll"}));        
        set("gender", "女性");                
        set("long", "fkll[2;37;0m
它是瘋狂的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fengkuang");
        set("owner_name", "瘋狂");
        set_temp("owner", "fengkuang");
        set_temp("owner_name", "瘋狂");
        ::setup();
}
