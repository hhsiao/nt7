// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("一隻青龍[2;37;0m[2;37;0m", ({"dragon"}));        
        set("gender", "男性");                
        set("long", "一隻青龍[2;37;0m
它是羅伯特的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "robert");
        set("owner_name", "羅伯特");
        set_temp("owner", "robert");
        set_temp("owner_name", "羅伯特");
        ::setup();
}
