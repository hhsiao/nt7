// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("寒江雪[2;37;0m[2;37;0m", ({"vivian"}));        
        set("gender", "女性");                
        set("long", "看上去十分的威嚴、矚目，充滿無窮的神氣。[2;37;0m
它是舟子恆的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "savio");
        set("owner_name", "舟子恆");
        set_temp("owner", "savio");
        set_temp("owner_name", "舟子恆");
        ::setup();
}
