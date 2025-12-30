// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m平一指[2;37;0m[2;37;0m", ({"qwe"}));        
        set("gender", "男性");                
        set("long", "shit[2;37;0m
它是丸五的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wane");
        set("owner_name", "丸五");
        set_temp("owner", "wane");
        set_temp("owner_name", "丸五");
        ::setup();
}
