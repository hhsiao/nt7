// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"sdada"}));        
        set("gender", "女性");                
        set("long", "大廈[2;37;0m
它是魚兒兒的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "yur");
        set("owner_name", "魚兒兒");
        set_temp("owner", "yur");
        set_temp("owner_name", "魚兒兒");
        ::setup();
}
