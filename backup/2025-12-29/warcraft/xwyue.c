// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("無耳貓[2;37;0m[2;37;0m", ({"yowo"}));        
        set("gender", "女性");                
        set("long", "無耳貓[2;37;0m
它是西山真茗的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xwyue");
        set("owner_name", "西山真茗");
        set_temp("owner", "xwyue");
        set_temp("owner_name", "西山真茗");
        ::setup();
}
