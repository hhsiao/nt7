// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小馬[2;37;0m[2;37;0m", ({"xiaoma"}));        
        set("gender", "女性");                
        set("long", "日行千里[2;37;0m
它是華小俠的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "hxx");
        set("owner_name", "華小俠");
        set_temp("owner", "hxx");
        set_temp("owner_name", "華小俠");
        ::setup();
}
