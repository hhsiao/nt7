// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m冰冰[2;37;0m[2;37;0m", ({"dongdong"}));        
        set("gender", "男性");                
        set("long", "$HIR$冰冰[2;37;0m
它是無量佛的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "dong");
        set("owner_name", "無量佛");
        set_temp("owner", "dong");
        set_temp("owner_name", "無量佛");
        ::setup();
}
