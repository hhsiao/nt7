// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("自行車[2;37;0m[2;37;0m", ({"zxcc"}));        
        set("gender", "男性");                
        set("long", "alias m whistle zxcc[2;37;0m
它是黃金糖的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "golddmm");
        set("owner_name", "黃金糖");
        set_temp("owner", "golddmm");
        set_temp("owner_name", "黃金糖");
        ::setup();
}
