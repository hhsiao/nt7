// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m騾子[2;37;0m[2;37;0m", ({"luozi"}));        
        set("gender", "女性");                
        set("long", "$HIB$騾子[2;37;0m
它是苦工柒的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xyggg");
        set("owner_name", "苦工柒");
        set_temp("owner", "xyggg");
        set_temp("owner_name", "苦工柒");
        ::setup();
}
