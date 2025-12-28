// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("飛機依[2;37;0m[2;37;0m", ({"horse"}));        
        set("gender", "男性");                
        set("long", "飛機依[2;37;0m
它是豐雞的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "iankg");
        set("owner_name", "豐雞");
        set_temp("owner", "iankg");
        set_temp("owner_name", "豐雞");
        ::setup();
}
