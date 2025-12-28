// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("輕輕龍[2;37;0m[2;37;0m", ({"longq"}));        
        set("gender", "男性");                
        set("long", "一隻蛇而已[2;37;0m
它是胡碟的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "butter");
        set("owner_name", "胡碟");
        set_temp("owner", "butter");
        set_temp("owner_name", "胡碟");
        ::setup();
}
