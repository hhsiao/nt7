// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("煙都[2;37;0m[2;37;0m", ({"shiyan"}));        
        set("gender", "男性");                
        set("long", "煙都大宗師[2;37;0m
它是古陵逝煙的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "guling");
        set("owner_name", "古陵逝煙");
        set_temp("owner", "guling");
        set_temp("owner_name", "古陵逝煙");
        ::setup();
}
