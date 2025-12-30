// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m龍龍[2;37;0m[2;37;0m", ({"longlong"}));        
        set("gender", "男性");                
        set("long", "$HIR$龍龍[2;37;0m
它是女劍俠的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "aaqq");
        set("owner_name", "女劍俠");
        set_temp("owner", "aaqq");
        set_temp("owner_name", "女劍俠");
        ::setup();
}
