// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小四兒[2;37;0m[2;37;0m", ({"sisi"}));        
        set("gender", "男性");                
        set("long", "小四兒[2;37;0m
它是四哥的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "four");
        set("owner_name", "四哥");
        set_temp("owner", "four");
        set_temp("owner_name", "四哥");
        ::setup();
}
