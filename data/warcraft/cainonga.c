// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("菜農獸[2;37;0m[2;37;0m", ({"cainongaa"}));        
        set("gender", "女性");                
        set("long", "挖菜的[2;37;0m
它是菜農啊的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "cainonga");
        set("owner_name", "菜農啊");
        set_temp("owner", "cainonga");
        set_temp("owner_name", "菜農啊");
        ::setup();
}
