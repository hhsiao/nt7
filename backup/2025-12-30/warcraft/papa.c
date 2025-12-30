// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("歐蕾歐[2;37;0m[2;37;0m", ({"oio"}));        
        set("gender", "男性");                
        set("long", "漂亮的[2;37;0m
它是怕怕的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "papa");
        set("owner_name", "怕怕");
        set_temp("owner", "papa");
        set_temp("owner_name", "怕怕");
        ::setup();
}
