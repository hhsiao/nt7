// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m噠噠[2;37;0m[2;37;0m", ({"dada"}));        
        set("gender", "男性");                
        set("long", "噠噠[2;37;0m
它是萌萌噠的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "menga");
        set("owner_name", "萌萌噠");
        set_temp("owner", "menga");
        set_temp("owner_name", "萌萌噠");
        ::setup();
}
