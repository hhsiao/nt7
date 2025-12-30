// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m蒼[1;37m麟[2;37;0m[2;37;0m", ({"pdk"}));        
        set("gender", "男性");                
        set("long", "上古神獸之一[2;37;0m
它是帝如來的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "parry");
        set("owner_name", "帝如來");
        set_temp("owner", "parry");
        set_temp("owner_name", "帝如來");
        ::setup();
}
