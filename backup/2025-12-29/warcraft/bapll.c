// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[33m黃金[2;37;0m[2;37;0m", ({"gold"}));        
        set("gender", "男性");                
        set("long", "移動的黃金 寶石 材料倉庫[2;37;0m
它是齊火的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "bapll");
        set("owner_name", "齊火");
        set_temp("owner", "bapll");
        set_temp("owner_name", "齊火");
        ::setup();
}
