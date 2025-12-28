// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("雞[2;37;0m[2;37;0m", ({"goldjjj"}));        
        set("gender", "男性");                
        set("long", "雞[2;37;0m
它是金雞的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "goldjj");
        set("owner_name", "金雞");
        set_temp("owner", "goldjj");
        set_temp("owner_name", "金雞");
        ::setup();
}
