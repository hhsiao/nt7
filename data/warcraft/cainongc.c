// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("菜農[2;37;0m[2;37;0m", ({"cainongd"}));        
        set("gender", "女性");                
        set("long", "菜農[2;37;0m
它是菜農才的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "cainongc");
        set("owner_name", "菜農才");
        set_temp("owner", "cainongc");
        set_temp("owner_name", "菜農才");
        ::setup();
}
