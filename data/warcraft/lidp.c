// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("練風[2;37;0m[2;37;0m", ({"lidoa"}));        
        set("gender", "男性");                
        set("long", "練風[2;37;0m
它是煉葉的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lidp");
        set("owner_name", "煉葉");
        set_temp("owner", "lidp");
        set_temp("owner_name", "煉葉");
        ::setup();
}
