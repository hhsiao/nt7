// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("哺哺[2;37;0m[2;37;0m", ({"bubu"}));        
        set("gender", "男性");                
        set("long", "哺哺[2;37;0m
它是勝光奇兵的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "janey");
        set("owner_name", "勝光奇兵");
        set_temp("owner", "janey");
        set_temp("owner_name", "勝光奇兵");
        ::setup();
}
