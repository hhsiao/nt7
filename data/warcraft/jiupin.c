// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("九品麒麟[2;37;0m[2;37;0m", ({"jiupinqilin"}));        
        set("gender", "男性");                
        set("long", "九品麒麟[2;37;0m
它是張時珍的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "jiupin");
        set("owner_name", "張時珍");
        set_temp("owner", "jiupin");
        set_temp("owner_name", "張時珍");
        ::setup();
}
