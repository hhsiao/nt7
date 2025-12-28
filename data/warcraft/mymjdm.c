// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("棋逢對手[2;37;0m[2;37;0m", ({"mydmgo"}));        
        set("gender", "女性");                
        set("long", "棋逢對手[2;37;0m
它是頂替於的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "mymjdm");
        set("owner_name", "頂替於");
        set_temp("owner", "mymjdm");
        set_temp("owner_name", "頂替於");
        ::setup();
}
