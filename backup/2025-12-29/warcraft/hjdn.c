// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("玫瑰[2;37;0m[2;37;0m", ({"roes"}));        
        set("gender", "男性");                
        set("long", "花[2;37;0m
它是風來鴨的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "hjdn");
        set("owner_name", "風來鴨");
        set_temp("owner", "hjdn");
        set_temp("owner_name", "風來鴨");
        ::setup();
}
