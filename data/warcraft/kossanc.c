// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m米叄兵散[2;37;0m[2;37;0m", ({"kossancpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是散兵叄米的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kossanc");
        set("owner_name", "散兵叄米");
        set_temp("owner", "kossanc");
        set_temp("owner_name", "散兵叄米");
        ::setup();
}
