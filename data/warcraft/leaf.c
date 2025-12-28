// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m高處不勝寒[2;37;0m[2;37;0m", ({"lcnely"}));        
        set("gender", "男性");                
        set("long", "這是一個豬頭[2;37;0m
它是櫻葉的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "leaf");
        set("owner_name", "櫻葉");
        set_temp("owner", "leaf");
        set_temp("owner_name", "櫻葉");
        ::setup();
}
