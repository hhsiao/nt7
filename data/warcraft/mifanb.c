// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("米飯班主[2;37;0m[2;37;0m", ({"mfb"}));        
        set("gender", "男性");                
        set("long", "米飯班主[2;37;0m
它是紅米飯的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "mifanb");
        set("owner_name", "紅米飯");
        set_temp("owner", "mifanb");
        set_temp("owner_name", "紅米飯");
        ::setup();
}
