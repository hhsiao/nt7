// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"dalong"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是頭盔的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "kua");
        set("owner_name", "頭盔");
        set_temp("owner", "kua");
        set_temp("owner_name", "頭盔");
        ::setup();
}
