// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m閻羅王[2;37;0m[2;37;0m", ({"alcn"}));        
        set("gender", "女性");                
        set("long", "閻羅王[2;37;0m
它是豬四的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "alon");
        set("owner_name", "豬四");
        set_temp("owner", "alon");
        set_temp("owner_name", "豬四");
        ::setup();
}
