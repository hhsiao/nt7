// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("豬[2;37;0m[2;37;0m", ({"goldlll"}));        
        set("gender", "男性");                
        set("long", "豬[2;37;0m
它是金豬的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "goldll");
        set("owner_name", "金豬");
        set_temp("owner", "goldll");
        set_temp("owner_name", "金豬");
        ::setup();
}
