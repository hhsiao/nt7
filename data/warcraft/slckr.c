// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m飛行太保[2;37;0m[2;37;0m", ({"flying"}));        
        set("gender", "男性");                
        set("long", "$HIB$飛行太保[2;37;0m
它是風行者的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "slckr");
        set("owner_name", "風行者");
        set_temp("owner", "slckr");
        set_temp("owner_name", "風行者");
        ::setup();
}
