// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m五花馬[2;37;0m[2;37;0m", ({"myma"}));        
        set("gender", "男性");                
        set("long", "一隻五花馬[2;37;0m
它是彩旗飄飄的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "caiqi");
        set("owner_name", "彩旗飄飄");
        set_temp("owner", "caiqi");
        set_temp("owner_name", "彩旗飄飄");
        ::setup();
}
