// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("性感女神[2;37;0m[2;37;0m", ({"xinggannvshen"}));        
        set("gender", "女性");                
        set("long", "她身材高挑，曲線畢露，渾身散發著一股成熟的氣息。[2;37;0m
它是莫得感情的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "bright");
        set("owner_name", "莫得感情");
        set_temp("owner", "bright");
        set_temp("owner_name", "莫得感情");
        ::setup();
}
