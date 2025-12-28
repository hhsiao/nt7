// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m輕舞飛揚[2;37;0m[2;37;0m", ({"dangcer"}));        
        set("gender", "男性");                
        set("long", "輕舞飛揚[2;37;0m
它是舞林至尊的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "dangwu");
        set("owner_name", "舞林至尊");
        set_temp("owner", "dangwu");
        set_temp("owner_name", "舞林至尊");
        ::setup();
}
