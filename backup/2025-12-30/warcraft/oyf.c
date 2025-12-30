// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m見證[2;37;0m[2;37;0m", ({"oyfgo"}));        
        set("gender", "男性");                
        set("long", "$HIW$見證[2;37;0m
它是哦揚風的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "oyf");
        set("owner_name", "哦揚風");
        set_temp("owner", "oyf");
        set_temp("owner_name", "哦揚風");
        ::setup();
}
