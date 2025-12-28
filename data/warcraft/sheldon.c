// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("虛空[2;37;0m[2;37;0m", ({"gdragon"}));        
        set("gender", "男性");                
        set("long", "虛空[2;37;0m
它是謝爾頓的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "sheldon");
        set("owner_name", "謝爾頓");
        set_temp("owner", "sheldon");
        set_temp("owner_name", "謝爾頓");
        ::setup();
}
