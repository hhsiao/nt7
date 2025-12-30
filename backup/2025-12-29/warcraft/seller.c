// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m大排[2;37;0m[2;37;0m", ({"zuoqi"}));        
        set("gender", "男性");                
        set("long", "1400cc[2;37;0m
它是小販的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "seller");
        set("owner_name", "小販");
        set_temp("owner", "seller");
        set_temp("owner_name", "小販");
        ::setup();
}
