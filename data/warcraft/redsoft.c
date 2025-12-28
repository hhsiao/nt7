// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m青龍[2;37;0m[2;37;0m", ({"ide"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是小夜的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "redsoft");
        set("owner_name", "小夜");
        set_temp("owner", "redsoft");
        set_temp("owner_name", "小夜");
        ::setup();
}
