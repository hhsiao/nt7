// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m印第安小紅馬[2;37;0m[2;37;0m", ({"horse"}));        
        set("gender", "男性");                
        set("long", "印第安小紅馬[2;37;0m
它是阿爾一的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "aliversa");
        set("owner_name", "阿爾一");
        set_temp("owner", "aliversa");
        set_temp("owner_name", "阿爾一");
        ::setup();
}
