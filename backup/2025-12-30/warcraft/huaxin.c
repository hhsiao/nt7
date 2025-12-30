// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("無極劍[2;37;0m[2;37;0m", ({"baihu"}));        
        set("gender", "男性");                
        set("long", "無極劍一劍劃出，你陷入半昏迷[2;37;0m
它是花心的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "huaxin");
        set("owner_name", "花心");
        set_temp("owner", "huaxin");
        set_temp("owner_name", "花心");
        ::setup();
}
