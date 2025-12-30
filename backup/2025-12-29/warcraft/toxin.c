// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m小毛驢[2;37;0m[2;37;0m", ({"xiaomaolv"}));        
        set("gender", "女性");                
        set("long", "一隻懶懶的小毛驢。[2;37;0m
它是鬍子長的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "toxin");
        set("owner_name", "鬍子長");
        set_temp("owner", "toxin");
        set_temp("owner_name", "鬍子長");
        ::setup();
}
