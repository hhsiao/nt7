// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m追風黃金獸[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "這就是傳說中的八駿，渾身金黃錦緞似的，龍相虎步、日行萬里。[2;37;0m
它是魯智深的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "luda");
        set("owner_name", "魯智深");
        set_temp("owner", "luda");
        set_temp("owner_name", "魯智深");
        ::setup();
}
