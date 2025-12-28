// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m聖火令[2;37;0m[2;37;0m", ({"shenghuo"}));        
        set("gender", "男性");                
        set("long", "聖火令是明教的鎮教聖物，似透明，非透明，令中隱隱有火焰飛騰。[2;37;0m
它是雲卿的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "yunqing");
        set("owner_name", "雲卿");
        set_temp("owner", "yunqing");
        set_temp("owner_name", "雲卿");
        ::setup();
}
