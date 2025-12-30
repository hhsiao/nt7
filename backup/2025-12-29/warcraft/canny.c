// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m殤[1;37m月[2;37;0m[2;37;0m", ({"arr"}));        
        set("gender", "男性");                
        set("long", "神獸[2;37;0m
它是白雲飄的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "canny");
        set("owner_name", "白雲飄");
        set_temp("owner", "canny");
        set_temp("owner_name", "白雲飄");
        ::setup();
}
