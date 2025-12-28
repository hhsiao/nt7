// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;36m眼[1;35m花[1;32m繚[1;31m亂[2;37;0m[2;37;0m[2;37;0m", ({"daze"}));        
        set("gender", "女性");                
        set("long", "眼花繚亂！[2;37;0m
它是冰雪飄渺的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "evilsnow");
        set("owner_name", "冰雪飄渺");
        set_temp("owner", "evilsnow");
        set_temp("owner_name", "冰雪飄渺");
        ::setup();
}
