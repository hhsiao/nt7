// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白虎[2;37;0m[2;37;0m", ({"dsy"}));        
        set("gender", "女性");                
        set("long", "這是一隻白虎[2;37;0m
它是船長的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "dsydxla");
        set("owner_name", "船長");
        set_temp("owner", "dsydxla");
        set_temp("owner_name", "船長");
        ::setup();
}
