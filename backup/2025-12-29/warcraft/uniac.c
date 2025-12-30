// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("老虎[2;37;0m[2;37;0m", ({"tig"}));        
        set("gender", "男性");                
        set("long", "大老虎[2;37;0m
它是葉三郎的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "uniac");
        set("owner_name", "葉三郎");
        set_temp("owner", "uniac");
        set_temp("owner_name", "葉三郎");
        ::setup();
}
