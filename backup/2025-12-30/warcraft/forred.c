// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m張揚[2;37;0m[2;37;0m", ({"wwbzy"}));        
        set("gender", "男性");                
        set("long", "揚哥出手，天下我有！[2;37;0m
它是李小胖的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "forred");
        set("owner_name", "李小胖");
        set_temp("owner", "forred");
        set_temp("owner_name", "李小胖");
        ::setup();
}
