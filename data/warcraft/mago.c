// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("吉他[2;37;0m[2;37;0m", ({"guide"}));        
        set("gender", "男性");                
        set("long", "吉他[2;37;0m
它是瘋狂無敵的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "mago");
        set("owner_name", "瘋狂無敵");
        set_temp("owner", "mago");
        set_temp("owner_name", "瘋狂無敵");
        ::setup();
}
