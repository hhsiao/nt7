// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m火鳳凰[2;37;0m[2;37;0m", ({"bird"}));        
        set("gender", "男性");                
        set("long", "遠古來的一隻會噴火的巨鳥。[2;37;0m
它是跑斷腿的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "pdt");
        set("owner_name", "跑斷腿");
        set_temp("owner", "pdt");
        set_temp("owner_name", "跑斷腿");
        ::setup();
}
