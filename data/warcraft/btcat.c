// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m青色的駱駝[2;37;0m[2;37;0m", ({"jinhu"}));        
        set("gender", "男性");                
        set("long", "$HIC$青色的駱駝[2;37;0m
它是歐陽醜的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "btcat");
        set("owner_name", "歐陽醜");
        set_temp("owner", "btcat");
        set_temp("owner_name", "歐陽醜");
        ::setup();
}
