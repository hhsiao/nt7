// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("金將軍[2;37;0m[2;37;0m", ({"yaojjj"}));        
        set("gender", "男性");                
        set("long", "金將軍[2;37;0m
它是藥緊急的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yaojj");
        set("owner_name", "藥緊急");
        set_temp("owner", "yaojj");
        set_temp("owner_name", "藥緊急");
        ::setup();
}
