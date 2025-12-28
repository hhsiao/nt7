// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m宮保雞丁[2;37;0m[2;37;0m", ({"pesia"}));        
        set("gender", "男性");                
        set("long", "宮保雞丁[2;37;0m
它是阿爾三的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "aliversc");
        set("owner_name", "阿爾三");
        set_temp("owner", "aliversc");
        set_temp("owner_name", "阿爾三");
        ::setup();
}
