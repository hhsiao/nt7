// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("龍[2;37;0m[2;37;0m", ({"longe"}));        
        set("gender", "男性");                
        set("long", "龍[2;37;0m
它是峨眉的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "emei");
        set("owner_name", "峨眉");
        set_temp("owner", "emei");
        set_temp("owner_name", "峨眉");
        ::setup();
}
