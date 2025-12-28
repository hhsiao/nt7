// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("風溼[2;37;0m[2;37;0m", ({"horse"}));        
        set("gender", "男性");                
        set("long", "風溼[2;37;0m
它是豐福的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "iankf");
        set("owner_name", "豐福");
        set_temp("owner", "iankf");
        set_temp("owner_name", "豐福");
        ::setup();
}
