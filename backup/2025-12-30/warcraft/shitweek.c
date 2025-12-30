// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("異形[2;37;0m[2;37;0m", ({"shit"}));        
        set("gender", "男性");                
        set("long", "異形[2;37;0m
它是周鈺翔的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "shitweek");
        set("owner_name", "周鈺翔");
        set_temp("owner", "shitweek");
        set_temp("owner_name", "周鈺翔");
        ::setup();
}
