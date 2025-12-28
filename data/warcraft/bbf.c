// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m火雲獸[2;37;0m[2;37;0m", ({"wwjr"}));        
        set("gender", "男性");                
        set("long", "$HIM$火雲獸[2;37;0m
它是邊不負的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "bbf");
        set("owner_name", "邊不負");
        set_temp("owner", "bbf");
        set_temp("owner_name", "邊不負");
        ::setup();
}
