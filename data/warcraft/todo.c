// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("雲影[2;37;0m[2;37;0m", ({"yunyin"}));        
        set("gender", "男性");                
        set("long", "無以名之[2;37;0m
它是獨孤問劍的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "todo");
        set("owner_name", "獨孤問劍");
        set_temp("owner", "todo");
        set_temp("owner_name", "獨孤問劍");
        ::setup();
}
