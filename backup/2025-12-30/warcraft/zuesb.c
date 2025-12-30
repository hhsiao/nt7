// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[30m墨玉[2;37;0m[2;37;0m[2;37;0m", ({"moyub"}));        
        set("gender", "女性");                
        set("long", "呵呵[2;37;0m
它是葉綠二風的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zuesb");
        set("owner_name", "葉綠二風");
        set_temp("owner", "zuesb");
        set_temp("owner_name", "葉綠二風");
        ::setup();
}
