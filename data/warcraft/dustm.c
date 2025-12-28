// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m肯德基[1;33m[2;37;0m[2;37;0m", ({"kfc"}));        
        set("gender", "男性");                
        set("long", "lalal[2;37;0m
它是客官來不的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "dustm");
        set("owner_name", "客官來不");
        set_temp("owner", "dustm");
        set_temp("owner_name", "客官來不");
        ::setup();
}
