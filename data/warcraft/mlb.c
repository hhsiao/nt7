// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("好大的蛋啊[2;37;0m[2;37;0m", ({"egg"}));        
        set("gender", "女性");                
        set("long", "$HIY$[2;37;0m
它是荷包雞蛋的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "mlb");
        set("owner_name", "荷包雞蛋");
        set_temp("owner", "mlb");
        set_temp("owner_name", "荷包雞蛋");
        ::setup();
}
