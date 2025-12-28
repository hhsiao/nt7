// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m真武麒麟[2;37;0m[2;37;0m", ({"geo"}));        
        set("gender", "男性");                
        set("long", "真武大帝的本命聖獸。[2;37;0m
它是風月無痕的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "george");
        set("owner_name", "風月無痕");
        set_temp("owner", "george");
        set_temp("owner_name", "風月無痕");
        ::setup();
}
